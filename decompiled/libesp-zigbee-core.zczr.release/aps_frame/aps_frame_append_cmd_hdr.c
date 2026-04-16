/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> aps_frame.o -> aps_frame_append_cmd_hdr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: aux_hdr */
/* WARNING: Unknown calling convention */

void aps_frame_append_cmd_hdr
               (zmsg_t *msg,_Bool is_bcast,_Bool is_ack_required,_Bool is_secured,
               secur_scf_key_id_t key_id)

{
  char *pcVar1;
  int iVar2;
  undefined3 in_register_0000202d;
  undefined3 in_register_00002031;
  undefined3 in_register_00002035;
  byte bStack_24;
  char cStack_23;
  aps_cmd_hdr_t aps_hdr;
  secur_aux_hdr_t aux_hdr;
  
  bStack_24 = (-(CONCAT31(in_register_0000202d,is_bcast) == 0) & 0xf8U) + 9 | is_secured << 5;
  cStack_23 = 0;
  pcVar1 = (char *)core_globals_get(CONCAT31(in_register_00002031,is_ack_required));
  cStack_23 = *pcVar1;
  *pcVar1 = cStack_23 + '\x01';
  iVar2 = zmsg_append_bytes(msg,2,&bStack_24);
  if (iVar2 == 0) goto _L0;
  while( true ) {
    __assert_func(0,0,0,0);
_L0:
    if (CONCAT31(in_register_00002035,is_secured) == 0) break;
    key_id = key_id | 0x20;
    aps_hdr.fcf = (uint8_t)key_id;
    iVar2 = zmsg_append_bytes(msg,0xd,&aps_hdr);
    if (iVar2 == 0) {
      return;
    }
  }
  return;
}

