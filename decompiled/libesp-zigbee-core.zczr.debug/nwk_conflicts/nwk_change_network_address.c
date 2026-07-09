/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_conflicts.o -> nwk_change_network_address
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Control flow encountered bad instruction data */

void nwk_change_network_address(void)

{
  undefined2 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 uStack_18;
  undefined2 auStack_12 [5];
  
  nwk_set_short_address();
  uVar2 = nwk_get_extended_address();
  uVar3 = nwk_get_short_address();
  iVar4 = nwk_address_update(uVar2,uVar3,auStack_12);
  if (iVar4 == 0) {
    iVar4 = nwk_neighbor_table_get_by_addr_ref(auStack_12[0]);
    if (iVar4 != 0) {
      log_write(1,"nwk_conflicts.c","BUG: address conflict neighbor, delete it");
      nwk_neighbor_table_delete(iVar4);
    }
    uVar1 = nwk_get_short_address();
    uStack_18 = (uint)CONCAT12((char)((ushort)uVar1 >> 8),CONCAT11((char)uVar1,0x10));
    nwk_handle_network_status_local(&uStack_18);
    return;
  }
  __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk_conflicts.c",0x3b,
                "nwk_change_network_address",0x10000);
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

