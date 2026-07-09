/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> aps_frame.o -> aps_frame_append_cmd_hdr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Control flow encountered bad instruction data */

void aps_frame_append_cmd_hdr(undefined4 param_1,int param_2,int param_3,byte param_4)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  undefined4 uVar4;
  byte bVar5;
  byte abStack_24 [16];
  undefined2 uStack_14;
  
  if (param_2 == 0) {
    bVar5 = 1;
  }
  else {
    bVar5 = 9;
  }
  if (param_3 != 0) {
    bVar5 = bVar5 | 0x20;
  }
  uStack_14 = (ushort)bVar5;
  pcVar2 = (char *)core_globals_get();
  cVar1 = *pcVar2;
  *pcVar2 = cVar1 + '\x01';
  uStack_14 = CONCAT11(cVar1,(undefined1)uStack_14);
  iVar3 = zmsg_append_bytes(param_1,2,&uStack_14);
  if (iVar3 == 0) {
    if (param_3 != 0) {
      abStack_24[0] = param_4 | 0x20;
      iVar3 = zmsg_append_bytes(param_1,0xd,abStack_24);
      if (iVar3 != 0) goto _L0;
    }
    uVar4 = zmsg_get_length(param_1);
    zmsg_set_offset(param_1,uVar4);
    return;
  }
  __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/aps/aps_frame.c",0x11c,
                "aps_frame_append_cmd_hdr",
                "(zmsg_append_bytes(msg, sizeof(aps_hdr), &aps_hdr)) == 0");
_L0:
  __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/aps/aps_frame.c",0x120,
                "aps_frame_append_cmd_hdr",
                "(zmsg_append_bytes(msg, __builtin_offsetof (secur_aux_hdr_t, key_seq), &aux_hdr)) == 0"
               );
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

