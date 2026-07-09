/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> aps_main.o -> aps_send_frame
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void aps_send_frame(undefined2 param_1,int *param_2)

{
  int iVar1;
  int iStack_1c;
  undefined4 uStack_18;
  undefined2 uStack_14;
  ushort uStack_12;
  
  if ((*(ushort *)(*param_2 + 0x16) & 4) == 0) {
    iStack_1c = 0;
    uStack_18 = 0;
    nwk_address_extended_by_short(&iStack_1c);
    iVar1 = aps_process_transmit_security(&iStack_1c,*param_2);
    if (iVar1 != 0) {
      return;
    }
  }
  iStack_1c = *param_2;
  uStack_12 = (byte)((uint)param_2[6] >> 2) & 0xff04 | 3;
  uStack_14 = *(undefined2 *)((int)param_2 + 0x16);
  uStack_18 = CONCAT22((short)param_2[5],param_1);
  nwk_nlde_data_request(&iStack_1c);
  return;
}

