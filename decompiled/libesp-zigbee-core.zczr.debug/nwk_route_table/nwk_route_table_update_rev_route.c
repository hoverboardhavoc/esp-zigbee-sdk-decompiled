/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_route_table.o -> nwk_route_table_update_rev_route
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_route_table_update_rev_route(int param_1,uint param_2,int param_3)

{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  int iVar4;
  uint uVar5;
  
  uVar5 = *(uint *)(param_1 + 0xc) >> 0x14 & 1 | (uint)(param_3 != 0);
  uVar1 = *(ushort *)(param_1 + 0xe);
  *(ushort *)(param_1 + 0xe) = (ushort)(uVar5 << 4) | uVar1 & 0xffef;
  uVar2 = (ushort)(param_3 == 2) << 3;
  uVar3 = (ushort)(uVar5 << 4);
  *(ushort *)(param_1 + 0xe) = uVar3 | uVar1 & 0xffe7 | uVar2;
  if (param_3 == 0) {
    *(ushort *)(param_1 + 0xe) = uVar3 | uVar1 & 0xffc7 | uVar2;
  }
  else {
    if ((*(ushort *)(param_1 + 2) != param_2) || ((*(ushort *)(param_1 + 0xe) & 8) != 0)) {
      *(ushort *)(param_1 + 0xe) = *(ushort *)(param_1 + 0xe) | 0x20;
    }
    *(ushort *)(param_1 + 0xe) = *(ushort *)(param_1 + 0xe) & 0xffbf;
  }
  if (*(ushort *)(param_1 + 2) != param_2) {
    *(undefined4 *)(param_1 + 4) = 0;
    iVar4 = core_globals_get();
    *(undefined1 *)(param_1 + 10) = *(undefined1 *)(iVar4 + 0xa25);
  }
  nwk_route_table_update_route(param_1,param_2);
  return;
}

