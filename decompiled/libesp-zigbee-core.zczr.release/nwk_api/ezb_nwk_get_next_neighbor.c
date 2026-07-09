/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> nwk_api.o -> ezb_nwk_get_next_neighbor
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 ezb_nwk_get_next_neighbor(int *param_1,int param_2)

{
  undefined1 uVar1;
  undefined2 uVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  
  if (param_1 != (int *)0x0) {
    uVar4 = 2;
    if (param_2 != 0) {
      iVar3 = nwk_neighbor_table_next(*param_1);
      *param_1 = iVar3;
      uVar4 = 5;
      if (iVar3 != 0) {
        nwk_neighbor_get_extaddr(param_2);
        uVar2 = nwk_neighbor_get_shortaddr(iVar3);
        uVar4 = *(undefined4 *)(iVar3 + 0xc);
        *(undefined2 *)(param_2 + 8) = uVar2;
        *(byte *)(param_2 + 10) = (byte)uVar4 & 3;
        *(byte *)(param_2 + 0xb) = (byte)(*(uint *)(iVar3 + 0xc) >> 2) & 0xf;
        *(byte *)(param_2 + 0xc) = (byte)(*(uint *)(iVar3 + 0xc) >> 10) & 1;
        uVar5 = *(uint *)(iVar3 + 0xc) >> 6 & 0xf;
        uVar1 = (undefined1)uVar5;
        if (3 < uVar5) {
          uVar1 = 3;
        }
        *(undefined1 *)(param_2 + 0xd) = uVar1;
        uVar1 = nwk_neighbor_get_lqa(iVar3);
        *(undefined1 *)(param_2 + 0xe) = uVar1;
        *(undefined1 *)(param_2 + 0xf) = *(undefined1 *)(iVar3 + 5);
        *(byte *)(param_2 + 0x10) = (byte)((uint)*(undefined4 *)(iVar3 + 0xc) >> 0x1a) & 7;
        *(char *)(param_2 + 0x11) = (char)(*(uint *)(iVar3 + 0xc) >> 0x12);
        if ((*(uint *)(iVar3 + 0xc) & 3) == 2) {
          *(uint *)(param_2 + 0x14) = *(uint *)(iVar3 + 0x14) >> 0x14 & 0xf;
          *(uint *)(param_2 + 0x18) = *(uint *)(iVar3 + 0x14) & 0xfffff;
        }
        else {
          *(undefined4 *)(param_2 + 0x14) = 0;
          *(undefined4 *)(param_2 + 0x18) = 0;
        }
        uVar4 = 0;
      }
    }
    return uVar4;
  }
  return 2;
}

