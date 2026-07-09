/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_forwarder.o -> nwk_fwd_handle_intrp_frame
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int nwk_fwd_handle_intrp_frame(undefined1 param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int iStack_2c;
  int iStack_28;
  undefined2 uStack_24;
  undefined2 uStack_22;
  undefined2 uStack_20;
  undefined2 uStack_1e;
  undefined2 uStack_1c;
  undefined2 uStack_1a;
  undefined2 uStack_18;
  undefined2 uStack_16;
  undefined1 uStack_14;
  undefined1 uStack_13;
  undefined1 uStack_12;
  
  iStack_2c = param_2[1];
  iStack_28 = param_2[2];
  uStack_24 = (undefined2)param_2[3];
  uStack_22 = *(undefined2 *)((int)param_2 + 0xe);
  uStack_20 = (undefined2)param_2[4];
  uStack_1e = *(undefined2 *)((int)param_2 + 0x12);
  uStack_1c = (undefined2)param_2[5];
  uStack_1a = *(undefined2 *)((int)param_2 + 0x16);
  uStack_18 = (undefined2)param_2[6];
  uStack_16 = *(undefined2 *)((int)param_2 + 0x1a);
  uStack_13 = *(undefined1 *)(*param_2 + 0x11);
  uStack_12 = *(undefined1 *)(*param_2 + 0x10);
  uStack_14 = param_1;
  iVar1 = zmsg_alloc(9);
  if (iVar1 == 0) {
    iVar2 = 1;
  }
  else {
    iVar2 = zmsg_append_bytes((char)param_2[8],param_2[9]);
    if (iVar2 == 0) {
      *(ushort *)(iVar1 + 0x16) = *(ushort *)(iVar1 + 0x16) | 8;
      iVar2 = nwk_handle_received_intrp_msg(iVar1,&iStack_2c);
    }
  }
  return iVar2;
}

