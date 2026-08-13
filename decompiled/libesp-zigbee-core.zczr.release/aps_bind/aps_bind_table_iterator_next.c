/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.release -> aps_bind.o -> aps_bind_table_iterator_next
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void aps_bind_table_iterator_next(char *param_1)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  
  if (*param_1 != '\0') {
    return;
  }
  iVar2 = core_globals_get();
  iVar3 = core_globals_get();
  iVar4 = *(int *)(param_1 + 4);
  if (iVar4 == 0) {
    uVar5 = bitmap_find_first_bit(*(undefined4 *)(iVar2 + 0x96c),*(undefined2 *)(iVar2 + 0x970));
    if (*(ushort *)(iVar2 + 0x970) <= uVar5) goto _L0;
    iVar4 = *(int *)(iVar2 + 0x968);
    iVar6 = bind_src_size();
    param_1[8] = '\0';
    param_1[9] = '\0';
    param_1[10] = '\0';
    param_1[0xb] = '\0';
    iVar4 = iVar6 * uVar5 + iVar4;
    *(int *)(param_1 + 4) = iVar4;
  }
  if (*(int *)(param_1 + 8) == 0) {
    uVar5 = 0xffff;
  }
  else {
    uVar5 = (*(int *)(param_1 + 8) - *(int *)(iVar3 + 0x974) >> 1) * -0x55555555 & 0xffff;
  }
  uVar5 = bitmap_find_next_bit(iVar4 + 6,*(undefined2 *)(iVar3 + 0x97c),uVar5 + 1 & 0xffff);
  if (uVar5 < *(ushort *)(iVar3 + 0x97c)) {
    iVar2 = *(int *)(iVar3 + 0x974);
_L183:
    *(uint *)(param_1 + 8) = iVar2 + uVar5 * 6;
    return;
  }
  if (*(int *)(param_1 + 4) == 0) goto _L0;
  iVar6 = *(int *)(iVar2 + 0x968);
  iVar4 = bind_src_size();
  uVar5 = (*(int *)(param_1 + 4) - iVar6) / iVar4 & 0xffff;
  iVar4 = iVar3;
  while (uVar5 = bitmap_find_next_bit
                           (*(undefined4 *)(iVar2 + 0x96c),*(undefined2 *)(iVar2 + 0x970),
                            uVar5 + 1 & 0xffff), uVar5 < *(ushort *)(iVar2 + 0x970)) {
    iVar2 = *(int *)(iVar2 + 0x968);
    iVar6 = bind_src_size();
    iVar3 = iVar4 + 0x1000;
    uVar1 = *(undefined2 *)(iVar4 + 0x97c);
    iVar6 = iVar6 * uVar5 + iVar2;
    *(int *)(param_1 + 4) = iVar6;
    uVar5 = bitmap_find_first_bit(iVar6 + 6,uVar1);
    if (uVar5 < *(ushort *)(iVar4 + 0x97c)) {
      iVar2 = *(int *)(iVar4 + 0x974);
      goto _L183;
    }
    __assert_func(0,0,0,0);
_L0:
    uVar5 = 0xffff;
    iVar4 = iVar3;
  }
  param_1[4] = '\0';
  param_1[5] = '\0';
  param_1[6] = '\0';
  param_1[7] = '\0';
  param_1[8] = '\0';
  param_1[9] = '\0';
  param_1[10] = '\0';
  param_1[0xb] = '\0';
_L0:
  *param_1 = '\x01';
  return;
}

