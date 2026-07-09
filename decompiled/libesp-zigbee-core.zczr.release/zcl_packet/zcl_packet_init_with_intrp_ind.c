/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> zcl_packet.o -> zcl_packet_init_with_intrp_ind
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zcl_packet_init_with_intrp_ind(void *param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0x87;
  if ((param_1 != (void *)0x0) && (uVar2 = 0x87, param_2 != 0)) {
    *(undefined4 *)((int)param_1 + 0x24) = *(undefined4 *)(param_2 + 0x20);
    iVar1 = zcl_packet_load_header();
    if (iVar1 == 0) {
      *(undefined2 *)((int)param_1 + 0x14) = 0;
      *(undefined2 *)((int)param_1 + 0x16) = *(undefined2 *)(param_2 + 0x1a);
      *(undefined2 *)((int)param_1 + 0x18) = *(undefined2 *)(param_2 + 0x18);
      memcpy(param_1,(void *)(param_2 + 2),10);
      memcpy((void *)((int)param_1 + 10),(void *)(param_2 + 0xe),10);
      *(undefined1 *)((int)param_1 + 0x1f) = *(undefined1 *)(param_2 + 0x25);
      uVar2 = 0;
    }
    else {
      uVar2 = 0x80;
    }
  }
  return uVar2;
}

