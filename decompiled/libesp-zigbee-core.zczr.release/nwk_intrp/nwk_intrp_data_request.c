/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> nwk_intrp.o -> nwk_intrp_data_request
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_intrp_data_request(void *param_1)

{
  int iVar1;
  undefined4 uStack_2c;
  undefined1 auStack_28 [10];
  undefined1 auStack_1e [10];
  undefined2 uStack_14;
  undefined2 uStack_12;
  
  uStack_2c = CONCAT22(uStack_2c._2_2_,0xb);
  iVar1 = zmsg_prepend_bytes(*(undefined4 *)((int)param_1 + 0x18),2,&uStack_2c);
  if (iVar1 == 0) {
    uStack_2c = *(undefined4 *)((int)param_1 + 0x18);
    uStack_12 = 0;
    memcpy(auStack_28,param_1,10);
    memcpy(auStack_1e,(void *)((int)param_1 + 0xc),10);
    uStack_14 = *(undefined2 *)((int)param_1 + 10);
    nwk_mm_data_request(0,&uStack_2c);
  }
  return;
}

