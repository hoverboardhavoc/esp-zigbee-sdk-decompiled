/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> aps_frame.o -> aps_frame_append_cmd_hdr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Variable defined which should be unmapped: aps_hdr */
/* WARNING: Unknown calling convention */

void aps_frame_append_cmd_hdr
               (zmsg_t *msg,_Bool is_bcast,_Bool is_ack_required,_Bool is_secured,
               secur_scf_key_id_t key_id)

{
  uint8_t uVar1;
  uint8_t *puVar2;
  int iVar3;
  undefined3 in_register_0000202d;
  undefined3 in_register_00002031;
  undefined3 in_register_00002035;
  byte abStack_24 [4];
  secur_aux_hdr_t aux_hdr;
  aps_cmd_hdr_t aps_hdr;
  
  if (CONCAT31(in_register_0000202d,is_bcast) == 0) {
    aux_hdr.src_address.field_0.u8[7] = 1;
  }
  else {
    aux_hdr.src_address.field_0.u8[7] = 9;
  }
  if (CONCAT31(in_register_00002035,is_secured) != 0) {
    aux_hdr.src_address.field_0.u8[7] = aux_hdr.src_address.field_0.u8[7] | 0x20;
  }
  aux_hdr.key_seq = '\0';
  puVar2 = (uint8_t *)core_globals_get(CONCAT31(in_register_00002031,is_ack_required));
  uVar1 = *puVar2;
  *puVar2 = uVar1 + '\x01';
  aux_hdr.key_seq = uVar1;
  iVar3 = zmsg_append_bytes(msg,2,(undefined1 *)((int)&aux_hdr.src_address.field_0 + 7));
  if (iVar3 == 0) {
    if (CONCAT31(in_register_00002035,is_secured) == 0) {
      return;
    }
  }
  else {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/aps/aps_frame.c",0x11c,
                  "aps_frame_append_cmd_hdr",
                  "(zmsg_append_bytes(msg, sizeof(aps_hdr), &aps_hdr)) == 0");
  }
  abStack_24[0] = (byte)key_id | 0x20;
  iVar3 = zmsg_append_bytes(msg,0xd,abStack_24);
  if (iVar3 == 0) {
    return;
  }
  __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/aps/aps_frame.c",0x120,
                "aps_frame_append_cmd_hdr",
                "(zmsg_append_bytes(msg, __builtin_offsetof (secur_aux_hdr_t, key_seq), &aux_hdr)) == 0"
               );
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

