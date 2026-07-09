/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> aps_bind.o -> aps_bind_table_iterator_next
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void aps_bind_table_iterator_next(char *param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  char *extraout_a1;
  uint uVar4;
  int iVar5;
  
  if (*param_1 == '\0') {
    iVar1 = core_globals_get();
    iVar2 = core_globals_get();
    if (*(int *)(param_1 + 4) == 0) {
      uVar4 = bitmap_find_first_bit(*(undefined4 *)(iVar1 + 0x96c),*(undefined2 *)(iVar1 + 0x970));
      if (*(ushort *)(iVar1 + 0x970) <= uVar4) {
        *param_1 = '\x01';
        return;
      }
      iVar5 = *(int *)(iVar1 + 0x968);
      uVar3 = bind_src_size();
      *(uint *)(param_1 + 4) = iVar5 + (uVar3 & 0xffff) * uVar4;
      param_1[8] = '\0';
      param_1[9] = '\0';
      param_1[10] = '\0';
      param_1[0xb] = '\0';
    }
    if (*(int *)(param_1 + 8) == 0) {
      uVar4 = 0xffff;
    }
    else {
      uVar4 = (*(int *)(param_1 + 8) - *(int *)(iVar2 + 0x974) >> 1) * -0x55555555 & 0xffff;
    }
    uVar4 = bitmap_find_next_bit
                      (*(int *)(param_1 + 4) + 6,*(undefined2 *)(iVar2 + 0x97c),uVar4 + 1 & 0xffff);
    if (uVar4 < *(ushort *)(iVar2 + 0x97c)) {
      *(uint *)(param_1 + 8) = uVar4 * 6 + *(int *)(iVar2 + 0x974);
    }
    else {
      if (*(int *)(param_1 + 4) == 0) {
        uVar4 = 0xffff;
      }
      else {
        iVar5 = *(int *)(iVar1 + 0x968);
        uVar4 = bind_src_size();
        uVar4 = (*(int *)(param_1 + 4) - iVar5) / (int)(uVar4 & 0xffff) & 0xffff;
      }
      uVar4 = bitmap_find_next_bit
                        (*(undefined4 *)(iVar1 + 0x96c),*(undefined2 *)(iVar1 + 0x970),
                         uVar4 + 1 & 0xffff);
      if (uVar4 < *(ushort *)(iVar1 + 0x970)) {
        iVar1 = *(int *)(iVar1 + 0x968);
        uVar3 = bind_src_size();
        iVar1 = (uVar3 & 0xffff) * uVar4 + iVar1;
        *(int *)(param_1 + 4) = iVar1;
        uVar4 = bitmap_find_first_bit(iVar1 + 6,*(undefined2 *)(iVar2 + 0x97c));
        if (*(ushort *)(iVar2 + 0x97c) <= uVar4) {
          uVar3 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/aps/aps_bind.c",0x195,
                                "aps_bind_table_iterator_next","dst_idx < dst_tbl->ent_nr");
          *extraout_a1 = '\0';
          extraout_a1[1] = '\0';
          extraout_a1[2] = '\0';
          extraout_a1[3] = '\0';
          extraout_a1[4] = '\0';
          extraout_a1[5] = '\0';
          extraout_a1[6] = '\0';
          extraout_a1[7] = '\0';
          extraout_a1[8] = '\0';
          extraout_a1[9] = '\0';
          extraout_a1[10] = '\0';
          extraout_a1[0xb] = '\0';
          uVar4 = 0;
          while ((uVar4 <= uVar3 && (*extraout_a1 == '\0'))) {
            aps_bind_table_iterator_next(extraout_a1);
            uVar4 = uVar4 + 1 & 0xffff;
          }
          return;
        }
        *(uint *)(param_1 + 8) = uVar4 * 6 + *(int *)(iVar2 + 0x974);
      }
      else {
        param_1[4] = '\0';
        param_1[5] = '\0';
        param_1[6] = '\0';
        param_1[7] = '\0';
        param_1[8] = '\0';
        param_1[9] = '\0';
        param_1[10] = '\0';
        param_1[0xb] = '\0';
        *param_1 = '\x01';
      }
    }
  }
  return;
}

