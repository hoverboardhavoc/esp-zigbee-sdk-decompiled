/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> aps_bind.o -> bind_dst_table_free
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void bind_dst_table_free(short *param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  if ((char)param_1[2] == '\0') {
    if ((((ushort)param_1[2] >> 8 & 1) != 0) || (*param_1 == -1)) goto _L0;
  }
  else {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/aps/aps_bind.c",0x6c,
                  "bind_dst_table_free","dst->ref_cnt == 0");
  }
  nwk_address_unlock_ref();
_L0:
  iVar1 = core_globals_get();
  uVar2 = *(undefined4 *)(iVar1 + 0x974);
  iVar1 = core_globals_get();
  uVar3 = *(undefined4 *)(iVar1 + 0x978);
  iVar1 = core_globals_get();
  mempool_free_ent(uVar2,uVar3,6,*(undefined2 *)(iVar1 + 0x97c),param_1);
  return;
}

