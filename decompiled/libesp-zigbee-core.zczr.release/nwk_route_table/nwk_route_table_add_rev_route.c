/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> nwk_route_table.o -> nwk_route_table_add_rev_route
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 nwk_route_table_add_rev_route(uint param_1,uint param_2,int param_3)

{
  int iVar1;
  int iVar2;
  ushort uVar3;
  undefined4 uVar4;
  
  if (param_1 < 0xfff8) {
    uVar4 = 2;
    if ((param_2 < 0xfff8) && (param_1 != param_2)) {
      iVar1 = nwk_route_table_find_or_create();
      uVar4 = 1;
      if (iVar1 != 0) {
        *(byte *)(iVar1 + 0xe) =
             (byte)(((uint)(param_3 != 0) | *(uint *)(iVar1 + 0xc) >> 0x14 & 1) << 4) |
             (param_3 == 2) << 3 | *(byte *)(iVar1 + 0xe) & 0xe7;
        uVar3 = *(ushort *)(iVar1 + 0xe);
        if (param_3 == 0) {
          uVar3 = uVar3 & 0xffdf;
        }
        else {
          if ((param_2 != *(ushort *)(iVar1 + 2)) || ((uVar3 & 8) != 0)) {
            *(ushort *)(iVar1 + 0xe) = uVar3 | 0x20;
          }
          uVar3 = *(ushort *)(iVar1 + 0xe) & 0xffbf;
        }
        *(ushort *)(iVar1 + 0xe) = uVar3;
        if (param_2 != *(ushort *)(iVar1 + 2)) {
          *(undefined4 *)(iVar1 + 4) = 0;
          iVar2 = core_globals_get();
          *(undefined1 *)(iVar1 + 10) = *(undefined1 *)(iVar2 + 0xa25);
        }
        nwk_route_table_update_route(iVar1,param_2);
        uVar4 = 0;
      }
    }
    return uVar4;
  }
  return 2;
}

