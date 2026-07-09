/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> aps_bind.o -> bind_table_find_src
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined2 * bind_table_find_src(int *param_1,uint param_2,uint param_3)

{
  int iVar1;
  undefined2 *puVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iStack_28;
  int iStack_24;
  
  iVar3 = core_globals_get();
  uVar5 = 0;
  do {
    uVar5 = bitmap_find_next_bit
                      (*(undefined4 *)(iVar3 + 0x96c),*(undefined2 *)(iVar3 + 0x970),uVar5);
    if (*(ushort *)(iVar3 + 0x970) <= uVar5) {
      return (undefined2 *)0x0;
    }
    iVar1 = *(int *)(iVar3 + 0x968);
    uVar4 = bind_src_size();
    puVar2 = (undefined2 *)(iVar1 + (uVar4 & 0xffff) * uVar5);
    if ((*(byte *)(puVar2 + 1) == param_2) && ((ushort)puVar2[2] == param_3)) {
      iVar1 = nwk_address_extended_by_ref(*puVar2,&iStack_28);
      if (iVar1 == 0) {
        if ((*param_1 == iStack_28) && (param_1[1] == iStack_24)) {
          return puVar2;
        }
      }
      else {
        __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/aps/aps_bind.c",0xa3,
                      "bind_table_find_src",
                      "(nwk_address_extended_by_ref(tmp_src->addr_ref, &tmp_src_addr)) == 0");
      }
    }
    uVar5 = uVar5 + 1 & 0xffff;
  } while( true );
}

