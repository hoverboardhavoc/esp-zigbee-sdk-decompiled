/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> mac_frame.o -> mac_frame_set_dstaddr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void mac_frame_set_dstaddr(undefined4 *param_1,char *param_2)

{
  undefined4 uVar1;
  ushort *puVar2;
  int iVar3;
  undefined4 *puVar4;
  
  puVar2 = (ushort *)*param_1;
  if ((*puVar2 >> 10 & 3) != 0) goto _L65;
  while( true ) {
    param_2 = (char *)__assert_func(0,0,0,0);
_L65:
    iVar3 = mac_fcf_skip_dst_panid_index();
    puVar4 = (undefined4 *)(iVar3 + (int)puVar2);
    if (*param_2 == '\x02') break;
    if (*param_2 == '\x03') {
      uVar1 = *(undefined4 *)(param_2 + 6);
      *puVar4 = *(undefined4 *)(param_2 + 2);
      puVar4[1] = uVar1;
      return;
    }
  }
  *(undefined2 *)puVar4 = *(undefined2 *)(param_2 + 2);
  return;
}

