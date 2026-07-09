/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> nwk_intrp.o -> nwk_handle_received_intrp_msg
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 nwk_handle_received_intrp_msg(undefined4 param_1,void *param_2)

{
  ushort uStack_32;
  undefined2 uStack_30;
  undefined1 auStack_2e [10];
  undefined2 uStack_24;
  undefined1 auStack_22 [10];
  undefined4 uStack_18;
  undefined1 uStack_14;
  undefined1 uStack_13;
  
  zmsg_read_bytes(0,2,&uStack_32);
  if ((uStack_32 & 3) != 3) {
    __assert_func(0,0,0,0);
  }
  zmsg_remove_header(param_1,2);
  uStack_30 = *(undefined2 *)((int)param_2 + 0x16);
  memcpy(auStack_2e,(void *)((int)param_2 + 10),10);
  uStack_24 = *(undefined2 *)((int)param_2 + 0x14);
  memcpy(auStack_22,param_2,10);
  uStack_14 = *(undefined1 *)((int)param_2 + 0x19);
  uStack_13 = *(undefined1 *)((int)param_2 + 0x1a);
  uStack_18 = param_1;
  nwk_intrp_data_indication(&uStack_30);
  return 0;
}

