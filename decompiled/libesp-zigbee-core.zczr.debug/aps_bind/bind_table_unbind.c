/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.debug -> aps_bind.o -> bind_table_unbind
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

uint bind_table_unbind(int param_1,int param_2)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = core_globals_get();
  uVar2 = (param_2 - *(int *)(iVar3 + 0x974) >> 1) * -0x55555555;
  iVar3 = core_globals_get();
  if ((uVar2 & 0xffff) < (uint)*(ushort *)(iVar3 + 0x97c)) {
    uVar2 = test_and_clr_bitmap(uVar2 & 0xffff,param_1 + 6);
    if (uVar2 == 0) {
      return 0;
    }
  }
  else {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/aps/aps_bind.c",0x83,
                  "bind_table_unbind",
                  "dst_idx < (((((*core_globals_get()).aps).ctx).bind_table).dst_tbl).ent_nr");
  }
  iVar3 = core_globals_get();
  if ((*(uint *)(iVar3 + 0x980) & 1) == 0) {
    aps_bind_table_remove_stored_bind(param_1,param_2);
  }
  iVar3 = bind_src_is_empty(param_1);
  if (iVar3 != 0) {
    bind_src_table_free(param_1);
  }
  cVar1 = *(char *)(param_2 + 4);
  *(char *)(param_2 + 4) = cVar1 + -1;
  if (cVar1 == '\x01') {
    bind_dst_table_free(param_2);
  }
  return uVar2;
}

