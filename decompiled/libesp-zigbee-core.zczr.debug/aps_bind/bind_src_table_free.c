/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> aps_bind.o -> bind_src_table_free
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void bind_src_table_free(short *param_1)

{
  undefined2 uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  iVar2 = bind_src_is_empty();
  if (iVar2 == 0) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/aps/aps_bind.c",99,
                  "bind_src_table_free","bind_src_is_empty(src)");
  }
  else if (*param_1 == -1) goto _L0;
  nwk_address_unlock_ref();
_L0:
  iVar2 = core_globals_get();
  uVar3 = *(undefined4 *)(iVar2 + 0x968);
  iVar2 = core_globals_get();
  uVar4 = *(undefined4 *)(iVar2 + 0x96c);
  uVar1 = bind_src_size();
  iVar2 = core_globals_get();
  mempool_free_ent(uVar3,uVar4,uVar1,*(undefined2 *)(iVar2 + 0x970),param_1);
  return;
}

