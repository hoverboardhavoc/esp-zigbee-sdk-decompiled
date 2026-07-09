/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> aps_main.o -> aps_send_frame
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void aps_send_frame(undefined2 param_1,int *param_2)

{
  int iVar1;
  undefined4 uStack_24;
  undefined4 uStack_20;
  int iStack_1c;
  undefined4 uStack_18;
  uint uStack_14;
  
  if ((*(ushort *)(*param_2 + 0x16) & 4) == 0) {
    uStack_24 = 0;
    uStack_20 = 0;
    nwk_address_extended_by_short(&uStack_24);
    iVar1 = aps_process_transmit_security(&uStack_24,*param_2);
    if (iVar1 != 0) {
      return;
    }
  }
  iStack_1c = *param_2;
  uStack_18 = CONCAT13(*(undefined1 *)((int)param_2 + 0x15),CONCAT12((char)param_2[5],param_1));
  uStack_14 = CONCAT12((char)(((uint)param_2[6] >> 4 & 1) << 2),*(undefined2 *)((int)param_2 + 0x16)
                      ) | 0x30000;
  nwk_nlde_data_request(&iStack_1c);
  return;
}

