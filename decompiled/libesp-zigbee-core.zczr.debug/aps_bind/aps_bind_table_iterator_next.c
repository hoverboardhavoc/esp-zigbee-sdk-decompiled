/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> aps_bind.o -> aps_bind_table_iterator_next
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void aps_bind_table_iterator_next(aps_bind_table_iterator_t *itor)

{
  int iVar1;
  int iVar2;
  size_t sVar3;
  aps_bind_src_t *paVar4;
  uint uVar5;
  aps_bind_table_iterator_t *itor_00;
  uint uVar6;
  int iVar7;
  
  if (itor->is_done == false) {
    iVar1 = core_globals_get();
    iVar2 = core_globals_get();
    if (itor->src == (aps_bind_src_t *)0x0) {
      uVar6 = bitmap_find_first_bit(*(undefined4 *)(iVar1 + 0x96c),*(undefined2 *)(iVar1 + 0x970));
      if (*(ushort *)(iVar1 + 0x970) <= uVar6) {
        itor->is_done = true;
        return;
      }
      iVar7 = *(int *)(iVar1 + 0x968);
      sVar3 = bind_src_size();
      itor->src = (aps_bind_src_t *)(iVar7 + (sVar3 & 0xffff) * uVar6);
      itor->dst = (aps_bind_dst_t *)0x0;
    }
    if (itor->dst == (aps_bind_dst_t *)0x0) {
      uVar6 = 0xffff;
    }
    else {
      uVar6 = ((int)itor->dst - *(int *)(iVar2 + 0x974) >> 1) * -0x55555555 & 0xffff;
    }
    uVar6 = bitmap_find_next_bit(itor->src + 1,*(undefined2 *)(iVar2 + 0x97c),uVar6 + 1 & 0xffff);
    if (uVar6 < *(ushort *)(iVar2 + 0x97c)) {
      itor->dst = (aps_bind_dst_t *)(uVar6 * 6 + *(int *)(iVar2 + 0x974));
    }
    else {
      if (itor->src == (aps_bind_src_t *)0x0) {
        uVar6 = 0xffff;
      }
      else {
        iVar7 = *(int *)(iVar1 + 0x968);
        sVar3 = bind_src_size();
        uVar6 = ((int)itor->src - iVar7) / (int)(sVar3 & 0xffff) & 0xffff;
      }
      uVar6 = bitmap_find_next_bit
                        (*(undefined4 *)(iVar1 + 0x96c),*(undefined2 *)(iVar1 + 0x970),
                         uVar6 + 1 & 0xffff);
      if (uVar6 < *(ushort *)(iVar1 + 0x970)) {
        iVar1 = *(int *)(iVar1 + 0x968);
        sVar3 = bind_src_size();
        paVar4 = (aps_bind_src_t *)((sVar3 & 0xffff) * uVar6 + iVar1);
        itor->src = paVar4;
        uVar6 = bitmap_find_first_bit(paVar4 + 1,*(undefined2 *)(iVar2 + 0x97c));
        if (*(ushort *)(iVar2 + 0x97c) <= uVar6) {
          uVar5 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/aps/aps_bind.c",0x195,
                                "aps_bind_table_iterator_next","dst_idx < dst_tbl->ent_nr");
          itor_00->is_done = false;
          itor_00->field_0x1 = 0;
          itor_00->field_0x2 = 0;
          itor_00->field_0x3 = 0;
          *(undefined1 *)&itor_00->src = 0;
          *(undefined1 *)((int)&itor_00->src + 1) = 0;
          *(undefined1 *)((int)&itor_00->src + 2) = 0;
          *(undefined1 *)((int)&itor_00->src + 3) = 0;
          *(undefined1 *)&itor_00->dst = 0;
          *(undefined1 *)((int)&itor_00->dst + 1) = 0;
          *(undefined1 *)((int)&itor_00->dst + 2) = 0;
          *(undefined1 *)((int)&itor_00->dst + 3) = 0;
          uVar6 = 0;
          while ((uVar6 <= uVar5 && (itor_00->is_done == false))) {
            aps_bind_table_iterator_next(itor_00);
            uVar6 = uVar6 + 1 & 0xffff;
          }
          return;
        }
        itor->dst = (aps_bind_dst_t *)(uVar6 * 6 + *(int *)(iVar2 + 0x974));
      }
      else {
        itor->src = (aps_bind_src_t *)0x0;
        itor->dst = (aps_bind_dst_t *)0x0;
        itor->is_done = true;
      }
    }
  }
  return;
}

