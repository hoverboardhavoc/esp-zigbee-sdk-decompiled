/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.debug -> aps_bind.o -> aps_bind_table_has_binding
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int aps_bind_table_has_binding(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int extraout_a1;
  
  iVar2 = core_globals_get();
  uVar1 = (param_2 - *(int *)(iVar2 + 0x974) >> 1) * -0x55555555;
  iVar2 = core_globals_get();
  if ((uVar1 & 0xffff) < (uint)*(ushort *)(iVar2 + 0x97c)) {
    iVar2 = core_globals_get();
    iVar2 = *(int *)(iVar2 + 0x968);
    iVar3 = core_globals_get();
    if ((param_1 - iVar2 >> 1) * -0x55555555 < (int)(uint)*(ushort *)(iVar3 + 0x970)) {
      iVar2 = test_bitmap(uVar1 & 0xffff,param_1 + 6);
      return iVar2;
    }
  }
  else {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/aps/aps_bind.c",0x169,
                  "aps_bind_table_has_binding",
                  "dst_idx < (((((*core_globals_get()).aps).ctx).bind_table).dst_tbl).ent_nr");
  }
  iVar2 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/aps/aps_bind.c",0x16a,
                        "aps_bind_table_has_binding",
                        "src - (((((*core_globals_get()).aps).ctx).bind_table).src_tbl).ents < (((((*core_globals_get()).aps).ctx).bind_table).src_tbl).ent_nr"
                       );
  if (extraout_a1 == 0) {
    uVar1 = 0xffff;
  }
  else {
    iVar3 = core_globals_get();
    uVar1 = (extraout_a1 - *(int *)(iVar3 + 0x974) >> 1) * -0x55555555 & 0xffff;
  }
  iVar3 = core_globals_get();
  uVar1 = bitmap_find_next_bit(iVar2 + 6,*(undefined2 *)(iVar3 + 0x97c),uVar1 + 1 & 0xffff);
  iVar2 = core_globals_get();
  if (uVar1 < *(ushort *)(iVar2 + 0x97c)) {
    iVar2 = core_globals_get();
    iVar2 = *(int *)(iVar2 + 0x974) + uVar1 * 6;
  }
  else {
    iVar2 = 0;
  }
  return iVar2;
}

