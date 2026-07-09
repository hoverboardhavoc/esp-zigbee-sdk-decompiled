/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> aps_frame.o -> aps_frame_append_cmd_hdr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void aps_frame_append_cmd_hdr(undefined4 param_1,int param_2,int param_3,byte param_4)

{
  char *pcVar1;
  int iVar2;
  undefined4 uVar3;
  byte bStack_24;
  char cStack_23;
  byte abStack_20 [16];
  
  bStack_24 = (-(param_2 == 0) & 0xf8U) + 9 | (byte)(param_3 << 5);
  cStack_23 = 0;
  pcVar1 = (char *)core_globals_get();
  cStack_23 = *pcVar1;
  *pcVar1 = cStack_23 + '\x01';
  iVar2 = zmsg_append_bytes(param_1,2,&bStack_24);
  if (iVar2 == 0) goto _L0;
  do {
    __assert_func(0,0,0,0);
_L0:
    if (param_3 == 0) break;
    param_4 = param_4 | 0x20;
    abStack_20[0] = param_4;
    iVar2 = zmsg_append_bytes(param_1,0xd,abStack_20);
  } while (iVar2 != 0);
  uVar3 = zmsg_get_length(param_1);
  zmsg_set_offset(param_1,uVar3);
  return;
}

