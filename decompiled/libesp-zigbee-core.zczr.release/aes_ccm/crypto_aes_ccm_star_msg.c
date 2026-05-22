/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.release -> aes_ccm.o -> crypto_aes_ccm_star_msg
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t crypto_aes_ccm_star_msg
                    (zmsg_t *msg,int mode,uint8_t *key,uint8_t *nonce,uint16_t ad_len,
                    uint16_t plaintext_len,uint8_t *tag,uint8_t tag_len)

{
  uint8_t *unaff_s0;
  ezb_err_t eVar1;
  int iVar2;
  size_t sVar3;
  int extraout_a1;
  undefined2 in_register_0000203a;
  uint uVar4;
  uint uVar5;
  undefined2 in_register_0000203e;
  size_t sVar6;
  uint8_t *puVar7;
  undefined3 in_register_00002045;
  uint uVar8;
  uint uVar9;
  uint8_t *unaff_s6;
  undefined2 uStack_27a;
  uint16_t uStack_278;
  uint16_t remaining_ad;
  uint16_t remaining;
  psa_key_id_t key_id;
  size_t finish_len;
  size_t produced;
  psa_key_id_t key_id_1;
  size_t tail_len;
  size_t produced_1;
  zmsg_chunk_t chunk;
  zmsg_chunk_t chunk_1;
  size_t tag_olen;
  undefined1 auStack_234 [4];
  uint8_t tail [16];
  undefined1 auStack_1e0 [4];
  psa_aead_operation_t op;
  
  uVar8 = CONCAT31(in_register_00002045,tag_len);
  sVar3 = CONCAT22(in_register_0000203e,plaintext_len);
  uVar5 = CONCAT22(in_register_0000203a,ad_len);
  if (((msg != (zmsg_t *)0x0) && (unaff_s0 = key, key != (uint8_t *)0x0)) &&
     (uVar4 = uVar5, sVar6 = sVar3, puVar7 = tag, uVar9 = uVar8, unaff_s6 = nonce,
     nonce != (uint8_t *)0x0)) goto _L0;
_L0:
  do {
    do {
      msg = (zmsg_t *)__assert_func(0,0,0,0);
      mode = extraout_a1;
      uVar4 = uVar5;
      sVar6 = sVar3;
      puVar7 = tag;
      uVar9 = uVar8;
_L0:
      uVar5 = uVar4;
      sVar3 = sVar6;
      tag = puVar7;
      uVar8 = uVar9;
      iVar2 = zmsg_get_length();
    } while (iVar2 < (int)(uVar4 + sVar6));
    if (uVar9 != 0) {
      _remaining = 0;
      memset(auStack_1e0,0,0x1b0);
      uVar5 = (uVar9 & 0x3f) << 0x10 | 0x5400100;
      uStack_27a = (undefined2)uVar4;
      key_id = 0;
      uStack_278 = (uint16_t)sVar6;
      iVar2 = crypto_psa_import_aes_key
                        (unaff_s0,uVar5,(uint)(mode != 0) * 0x100 + 0x100,(psa_key_id_t *)&remaining
                        );
      if (iVar2 == 0) {
        if (mode == 0) {
          iVar2 = psa_aead_encrypt_setup();
        }
        else {
          iVar2 = psa_aead_decrypt_setup(auStack_1e0,_remaining,uVar5);
        }
        if (((iVar2 == 0) && (iVar2 = psa_aead_set_lengths(auStack_1e0,uVar4,sVar6), iVar2 == 0)) &&
           (iVar2 = psa_aead_set_nonce(auStack_1e0,unaff_s6,0xd), iVar2 == 0)) {
          zmsg_get_first_chunk(msg,0,&uStack_27a,&produced_1);
          while ((ushort)chunk.data != 0) {
            iVar2 = psa_aead_update_ad(auStack_1e0,chunk.buffer);
            if (iVar2 != 0) goto _L0;
            zmsg_get_next_chunk(&uStack_27a,&produced_1);
          }
          zmsg_get_first_chunk(msg,uVar4,&uStack_278,&produced_1);
          while( true ) {
            if ((ushort)chunk.data == 0) {
              if (mode == 0) {
                chunk_1.len = 0;
                chunk_1._10_2_ = 0;
                iVar2 = psa_aead_finish(auStack_1e0,auStack_234,0x10,&key_id,puVar7,uVar9,
                                        &chunk_1.len);
              }
              else {
                iVar2 = psa_aead_verify(auStack_1e0,auStack_234,0x10,&key_id,puVar7,uVar9);
              }
              goto _L0;
            }
            finish_len = 0;
            iVar2 = psa_aead_update(auStack_1e0,chunk.buffer,(ushort)chunk.data,&finish_len);
            if (iVar2 != 0) goto _L0;
            uVar5 = (uint)(ushort)chunk.data;
            unaff_s0 = (uint8_t *)0x0;
            sVar3 = finish_len;
            if (uVar5 != finish_len) break;
            zmsg_get_next_chunk(&uStack_278,&produced_1);
          }
          goto _L0;
        }
      }
_L0:
      psa_aead_abort(auStack_1e0);
      sVar3 = _remaining;
      goto _L0;
    }
    produced = 0;
    remaining_ad = (uint16_t)sVar6;
    memset(auStack_234,0,0x54);
    key_id_1 = 0;
    iVar2 = crypto_psa_import_aes_key
                      (unaff_s0,0x4c01300,(uint)(mode != 0) * 0x100 + 0x100,&produced);
    if (iVar2 != 0) {
_L0:
      psa_cipher_abort(auStack_234);
      sVar3 = produced;
_L0:
      if (sVar3 != 0) {
        psa_destroy_key();
      }
      if (iVar2 == -0x87) {
        eVar1 = 2;
      }
      else {
        if (-0x87 < iVar2) {
          return -(uint)(iVar2 != 0);
        }
        eVar1 = 0x13;
        if ((iVar2 != -0x95) && (eVar1 = 1, iVar2 != -0x8a)) {
          return -1;
        }
      }
      return eVar1;
    }
    if (mode == 0) {
      iVar2 = psa_cipher_encrypt_setup();
    }
    else {
      iVar2 = psa_cipher_decrypt_setup(auStack_234,produced,0x4c01300);
    }
    if ((iVar2 != 0) || (iVar2 = psa_cipher_set_iv(auStack_234,unaff_s6,0xd), iVar2 != 0)) goto _L0;
    zmsg_get_first_chunk(msg,uVar4,&remaining_ad,&chunk.len);
    while (uVar5 = (uint)(ushort)chunk_1.data, uVar5 != 0) {
      tail_len = 0;
      iVar2 = psa_cipher_update(auStack_234,chunk_1.buffer,uVar5,&tail_len);
      if (iVar2 != 0) goto _L0;
      uVar5 = (uint)(ushort)chunk_1.data;
      unaff_s0 = (uint8_t *)0x0;
      sVar3 = tail_len;
      if (uVar5 != tail_len) goto _L0;
      zmsg_get_next_chunk(&remaining_ad,&chunk.len);
    }
    iVar2 = psa_cipher_finish(auStack_234,&chunk_1.len,0x10,&key_id_1);
    if ((iVar2 != 0) || (unaff_s0 = (uint8_t *)0x0, sVar3 = key_id_1, key_id_1 == 0)) goto _L0;
  } while( true );
}

