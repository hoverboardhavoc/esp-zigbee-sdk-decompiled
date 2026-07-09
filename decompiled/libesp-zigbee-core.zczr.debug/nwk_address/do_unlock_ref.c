/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_address.o -> do_unlock_ref
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void do_unlock_ref(undefined4 *param_1,int param_2)

{
  char cVar1;
  int iVar2;
  
  iVar2 = check_table_ref(param_2,*param_1,*(undefined2 *)(param_1 + 2));
  if (iVar2 == 0) {
    return;
  }
  iVar2 = param_1[1] + param_2 * 0x12;
  cVar1 = *(char *)(iVar2 + 0x10);
  if (cVar1 == '\0') {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk_address.c",0x1a5,
                  "do_unlock_ref","ent->ref_cnt > 0");
  }
  else {
    *(char *)(iVar2 + 0x10) = cVar1 + -1;
    if (cVar1 != '\x01') {
      return;
    }
    if ((*(ushort *)(iVar2 + 0x10) & 0xc00) != 0) {
      nwk_address_delete(param_2);
      return;
    }
  }
  addr_table_lru_add(param_1,param_2);
  return;
}

