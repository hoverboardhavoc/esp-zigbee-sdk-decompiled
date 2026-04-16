/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> aps_secur.o -> aps_secur_unsecure_msg_by_key_pair
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t aps_secur_unsecure_msg_by_key_pair
                    (aps_device_key_pair_t *key_pair,zmsg_t *msg,secur_aux_hdr_t *aux_hdr)

{
  uint uVar1;
  byte bVar2;
  undefined4 uVar3;
  ezb_err_t eVar4;
  uint uVar5;
  undefined4 local_40;
  secur_ccm_nonce_t ccm_nonce;
  uint8_t key [16];
  
  uVar1 = aux_hdr->frame_cntr;
  aps_secur_key_pair_get_key(key_pair,&ccm_nonce.security_control,aux_hdr->scf & SECUR_SCF_KL_KEY);
  uVar5 = 0x10;
  do {
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1 & 0xff;
  } while ((&ccm_nonce.security_control)[uVar5] == '\0');
  if (uVar5 == 0) {
    eVar4 = 0x13;
  }
  else {
    local_40 = *(undefined4 *)&(aux_hdr->src_address).field_0;
    ccm_nonce.source_address.field_0.u64._0_4_ =
         *(undefined4 *)((int)&(aux_hdr->src_address).field_0 + 4);
    ccm_nonce.source_address.field_0.u64._4_4_ = aux_hdr->frame_cntr;
    ccm_nonce.frame_counter._0_1_ = aux_hdr->scf;
    bVar2 = (byte)ccm_nonce.frame_counter & 7;
    uVar3 = zmsg_get_offset(msg);
    eVar4 = secur_unsecure_msg(bVar2,&ccm_nonce.security_control,&local_40,msg,uVar3);
    if (eVar4 == 0) {
      if ((key_pair->incoming_frame_cntr == 0xffffffff) || (key_pair->incoming_frame_cntr < uVar1))
      {
        key_pair->incoming_frame_cntr = uVar1;
      }
      else {
        eVar4 = 0x13;
      }
    }
  }
  return eVar4;
}

