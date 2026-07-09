/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> aps_main.o -> apsde_data_request_continue
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int apsde_data_request_continue(int *param_1,ushort param_2)

{
  int *unaff_s0;
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  ushort uStack_12;
  
  uStack_12 = param_2;
  if ((param_1 == (int *)0x0) || (unaff_s0 = param_1, *param_1 == 0)) {
    __assert_func(0,0,0,0);
  }
  if ((0xfff7 < uStack_12) && (uStack_12 != 0xfffe)) {
    *(byte *)(unaff_s0 + 6) = *(byte *)(unaff_s0 + 6) & 0xf9;
  }
  if ((*(byte *)(unaff_s0 + 6) & 2) == 0) {
    *(byte *)(unaff_s0 + 6) = *(byte *)(unaff_s0 + 6) & 0xfb;
  }
  uVar2 = zmsg_get_length();
  uVar4 = unaff_s0[6];
  iVar1 = 0x3a0;
  uVar4 = aps_get_max_asdu(uVar4 >> 2 & 1,uVar4 & 1,uVar4 >> 3 & 1);
  if (((uVar2 <= uVar4) && (iVar1 = zmsg_add_footer(*unaff_s0,unaff_s0,0x1c), iVar1 == 0)) &&
     (iVar1 = zmsg_add_footer(*unaff_s0,&uStack_12,2), iVar1 == 0)) {
    iVar3 = core_globals_get();
    zmsg_queue_enqueue(iVar3 + 0x2c,*unaff_s0);
    iVar3 = core_globals_get();
    tasklet_post(iVar3 + 0x1c);
  }
  return iVar1;
}

