/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.release -> aps_bind.o -> aps_bind_table_iterator_next
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void aps_bind_table_iterator_next(aps_bind_table_iterator_t *itor)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  aps_bind_src_t *paVar4;
  uint uVar5;
  size_t sVar6;
  int iVar7;
  
  if (itor->is_done != false) {
    return;
  }
  iVar2 = core_globals_get();
  iVar3 = core_globals_get();
  paVar4 = itor->src;
  if (paVar4 == (aps_bind_src_t *)0x0) {
    uVar5 = bitmap_find_first_bit(*(undefined4 *)(iVar2 + 0x96c),*(undefined2 *)(iVar2 + 0x970));
    if (*(ushort *)(iVar2 + 0x970) <= uVar5) goto _L0;
    iVar7 = *(int *)(iVar2 + 0x968);
    sVar6 = bind_src_size();
    itor->dst = (aps_bind_dst_t *)0x0;
    paVar4 = (aps_bind_src_t *)(sVar6 * uVar5 + iVar7);
    itor->src = paVar4;
  }
  if (itor->dst == (aps_bind_dst_t *)0x0) {
    uVar5 = 0xffff;
  }
  else {
    uVar5 = ((int)itor->dst - *(int *)(iVar3 + 0x974) >> 1) * -0x55555555 & 0xffff;
  }
  uVar5 = bitmap_find_next_bit(paVar4 + 1,*(undefined2 *)(iVar3 + 0x97c),uVar5 + 1 & 0xffff);
  if (uVar5 < *(ushort *)(iVar3 + 0x97c)) {
    iVar2 = *(int *)(iVar3 + 0x974);
_L178:
    itor->dst = (aps_bind_dst_t *)(iVar2 + uVar5 * 6);
    return;
  }
  if (itor->src == (aps_bind_src_t *)0x0) goto _L0;
  iVar7 = *(int *)(iVar2 + 0x968);
  sVar6 = bind_src_size();
  uVar5 = ((int)itor->src - iVar7) / (int)sVar6 & 0xffff;
  iVar7 = iVar3;
  while (uVar5 = bitmap_find_next_bit
                           (*(undefined4 *)(iVar2 + 0x96c),*(undefined2 *)(iVar2 + 0x970),
                            uVar5 + 1 & 0xffff), uVar5 < *(ushort *)(iVar2 + 0x970)) {
    iVar2 = *(int *)(iVar2 + 0x968);
    sVar6 = bind_src_size();
    iVar3 = iVar7 + 0x1000;
    uVar1 = *(undefined2 *)(iVar7 + 0x97c);
    paVar4 = (aps_bind_src_t *)(sVar6 * uVar5 + iVar2);
    itor->src = paVar4;
    uVar5 = bitmap_find_first_bit(paVar4 + 1,uVar1);
    if (uVar5 < *(ushort *)(iVar7 + 0x97c)) {
      iVar2 = *(int *)(iVar7 + 0x974);
      goto _L178;
    }
    __assert_func(0,0,0,0);
_L0:
    uVar5 = 0xffff;
    iVar7 = iVar3;
  }
  itor->src = (aps_bind_src_t *)0x0;
  itor->dst = (aps_bind_dst_t *)0x0;
_L0:
  itor->is_done = true;
  return;
}

