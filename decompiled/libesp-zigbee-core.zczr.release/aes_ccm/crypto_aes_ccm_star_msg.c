/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> aes_ccm.o -> crypto_aes_ccm_star_msg
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Type propagation algorithm not settling */

int crypto_aes_ccm_star_msg
              (int param_1,int param_2,int param_3,int param_4,uint param_5,uint param_6,
              undefined4 param_7,uint param_8)

{
  int unaff_s0;
  int iVar1;
  int iVar2;
  int extraout_a1;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  uint uVar6;
  int unaff_s6;
  uint uVar7;
  undefined2 uStack_27a;
  undefined2 uStack_278;
  undefined2 uStack_276;
  int aiStack_274 [6];
  undefined1 auStack_25c [4];
  undefined4 uStack_258;
  ushort uStack_254;
  undefined1 auStack_250 [4];
  undefined4 uStack_24c;
  ushort uStack_248;
  undefined4 auStack_244 [4];
  undefined1 auStack_234 [84];
  undefined1 auStack_1e0 [440];
  
  if (((param_1 != 0) && (unaff_s0 = param_3, param_3 != 0)) &&
     (uVar3 = param_5, uVar4 = param_6, uVar5 = param_7, uVar6 = param_8, unaff_s6 = param_4,
     param_4 != 0)) goto _L0;
_L0:
  do {
    do {
      param_1 = __assert_func(0,0,0,0);
      param_2 = extraout_a1;
      uVar3 = param_5;
      uVar4 = param_6;
      uVar5 = param_7;
      uVar6 = param_8;
_L0:
      param_5 = uVar3;
      param_6 = uVar4;
      param_7 = uVar5;
      param_8 = uVar6;
      iVar2 = zmsg_get_length();
    } while (iVar2 < (int)(uVar3 + uVar4));
    if (uVar6 != 0) {
      aiStack_274[0] = 0;
      memset(auStack_1e0,0,0x1b0);
      uVar7 = (uVar6 & 0x3f) << 0x10 | 0x5400100;
      uStack_27a = (undefined2)uVar3;
      aiStack_274[1] = 0;
      uStack_278 = (short)uVar4;
      iVar2 = crypto_psa_import_aes_key_constprop_0
                        (unaff_s0,uVar7,(uint)(param_2 != 0) * 0x100 + 0x100,aiStack_274);
      if (iVar2 == 0) {
        if (param_2 == 0) {
          iVar2 = psa_aead_encrypt_setup();
        }
        else {
          iVar2 = psa_aead_decrypt_setup(auStack_1e0,aiStack_274[0],uVar7);
        }
        if (((iVar2 == 0) && (iVar2 = psa_aead_set_lengths(auStack_1e0,uVar3,uVar4), iVar2 == 0)) &&
           (iVar2 = psa_aead_set_nonce(auStack_1e0,unaff_s6,0xd), iVar2 == 0)) {
          zmsg_get_first_chunk(param_1,0,&uStack_27a,auStack_25c);
          while (uStack_254 != 0) {
            iVar2 = psa_aead_update_ad(auStack_1e0,uStack_258);
            if (iVar2 != 0) goto _L0;
            zmsg_get_next_chunk(&uStack_27a,auStack_25c);
          }
          zmsg_get_first_chunk(param_1,uVar3,&uStack_278,auStack_25c);
          while( true ) {
            if (uStack_254 == 0) {
              if (param_2 == 0) {
                auStack_244[0] = 0;
                iVar2 = psa_aead_finish(auStack_1e0,auStack_234,0x10,aiStack_274 + 1,uVar5,uVar6,
                                        auStack_244);
              }
              else {
                iVar2 = psa_aead_verify(auStack_1e0,auStack_234,0x10,aiStack_274 + 1,uVar5,uVar6);
              }
              goto _L0;
            }
            aiStack_274[2] = 0;
            iVar2 = psa_aead_update(auStack_1e0,uStack_258,uStack_254,aiStack_274 + 2);
            if (iVar2 != 0) goto _L0;
            param_5 = (uint)uStack_254;
            unaff_s0 = 0;
            param_6 = aiStack_274[2];
            if (param_5 != aiStack_274[2]) break;
            zmsg_get_next_chunk(&uStack_278,auStack_25c);
          }
          goto _L0;
        }
      }
_L0:
      psa_aead_abort(auStack_1e0);
      iVar1 = aiStack_274[0];
      goto _L0;
    }
    aiStack_274[3] = 0;
    uStack_276 = (short)uVar4;
    memset(auStack_234,0,0x54);
    aiStack_274[4] = 0;
    iVar2 = crypto_psa_import_aes_key_constprop_0
                      (unaff_s0,0x4c01300,(uint)(param_2 != 0) * 0x100 + 0x100,aiStack_274 + 3);
    if (iVar2 != 0) {
_L0:
      psa_cipher_abort(auStack_234);
      iVar1 = aiStack_274[3];
_L0:
      if (iVar1 != 0) {
        psa_destroy_key();
      }
      if (iVar2 == -0x87) {
        iVar1 = 2;
      }
      else {
        if (-0x87 < iVar2) {
          return -(uint)(iVar2 != 0);
        }
        iVar1 = 0x13;
        if ((iVar2 != -0x95) && (iVar1 = 1, iVar2 != -0x8a)) {
          return -1;
        }
      }
      return iVar1;
    }
    if (param_2 == 0) {
      iVar2 = psa_cipher_encrypt_setup();
    }
    else {
      iVar2 = psa_cipher_decrypt_setup(auStack_234,aiStack_274[3],0x4c01300);
    }
    if ((iVar2 != 0) || (iVar2 = psa_cipher_set_iv(auStack_234,unaff_s6,0xd), iVar2 != 0)) goto _L0;
    zmsg_get_first_chunk(param_1,uVar3,&uStack_276,auStack_250);
    while (param_5 = (uint)uStack_248, param_5 != 0) {
      aiStack_274[5] = 0;
      iVar2 = psa_cipher_update(auStack_234,uStack_24c,param_5,aiStack_274 + 5);
      if (iVar2 != 0) goto _L0;
      param_5 = (uint)uStack_248;
      unaff_s0 = 0;
      param_6 = aiStack_274[5];
      if (param_5 != aiStack_274[5]) goto _L0;
      zmsg_get_next_chunk(&uStack_276,auStack_250);
    }
    iVar2 = psa_cipher_finish(auStack_234,auStack_244,0x10,aiStack_274 + 4);
    if ((iVar2 != 0) || (unaff_s0 = 0, param_6 = aiStack_274[4], aiStack_274[4] == 0)) goto _L0;
  } while( true );
}

