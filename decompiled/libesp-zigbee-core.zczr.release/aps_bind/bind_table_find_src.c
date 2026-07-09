/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> aps_bind.o -> bind_table_find_src
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined2 * bind_table_find_src(int *param_1,uint param_2,uint param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined2 *puVar5;
  int iStack_28;
  int iStack_24;
  
  iVar1 = core_globals_get();
  uVar3 = 0;
  do {
    uVar3 = bitmap_find_next_bit
                      (*(undefined4 *)(iVar1 + 0x96c),*(undefined2 *)(iVar1 + 0x970),uVar3);
    if (*(ushort *)(iVar1 + 0x970) <= uVar3) {
      return (undefined2 *)0x0;
    }
    iVar4 = *(int *)(iVar1 + 0x968);
    iVar2 = bind_src_size();
    puVar5 = (undefined2 *)(iVar4 + uVar3 * iVar2);
    if ((*(byte *)(puVar5 + 1) == param_2) && ((ushort)puVar5[2] == param_3)) {
      iVar2 = nwk_address_extended_by_ref(*puVar5,&iStack_28);
      if (iVar2 != 0) {
        __assert_func(0,0,0,0);
      }
      if ((iStack_28 == *param_1) && (iStack_24 == param_1[1])) {
        return puVar5;
      }
    }
    uVar3 = uVar3 + 1 & 0xffff;
  } while( true );
}

