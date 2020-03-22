package org.openquantumsafe;

import org.openquantumsafe.*;
import java.util.ArrayList;
import java.util.Arrays;

public class Sig_Test {

    public static void main(String[] args) {
        System.out.println("Supported signatures:");
        Common.print_list(Sigs.get_supported_sigs());
        System.out.println();

        System.out.println("Enabled signatures:");
        Common.print_list(Sigs.get_enabled_sigs());
        System.out.println();

        byte[] message = "This is the message to sign".getBytes();

        String sig_name = "DEFAULT";
        Signature signer = new Signature(sig_name);
        signer.print_details();
        System.out.println();

        long t = System.currentTimeMillis();
        byte[] signer_public_key = signer.generate_keypair();
        long timeElapsed = System.currentTimeMillis() - t;

        byte[] signer_pk = signer.export_public_key();
        byte[] signer_sk = signer.export_secret_key();

        System.out.println("Signer public key:");
        System.out.println(Common.chopHex(signer_public_key));
        System.out.println("\nIt took " + timeElapsed + " millisecs to generate the key pair.");

        t = System.currentTimeMillis();
        byte[] signature = signer.sign(message);
        System.out.println("It took " + (System.currentTimeMillis() - t) + " millisecs to sign the message.");

        Signature verifier = new Signature(sig_name);

        t = System.currentTimeMillis();
        boolean is_valid = verifier.verify(message, signature, signer_pk);
        System.out.println("It took " + (System.currentTimeMillis() - t) + " millisecs to verify the signature.");

        System.out.println("\nSignature:");
        System.out.println(Common.chopHex(signature));

        System.out.println("\nValid signature? " + is_valid);

        signer.free_sig();
        verifier.free_sig();
    }

}
