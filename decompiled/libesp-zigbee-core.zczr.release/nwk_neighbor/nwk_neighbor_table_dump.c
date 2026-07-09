/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> nwk_neighbor.o -> nwk_neighbor_table_dump
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_neighbor_table_dump(void)

{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined2 *puVar5;
  undefined2 uStack_2a;
  undefined4 uStack_28;
  undefined4 uStack_24;
  
  puVar5 = (undefined2 *)0x0;
  log_write(3,"nwk_neighbor.c","Dump NWK Neighbor Table");
  while (puVar5 = (undefined2 *)nwk_neighbor_table_next(puVar5), puVar5 != (undefined2 *)0x0) {
    nwk_address_by_ref(*puVar5,&uStack_2a,&uStack_28);
    uVar4 = uStack_24;
    uVar3 = uStack_28;
    uVar2 = uStack_2a;
    uVar1 = *puVar5;
    nwk_neighbor_get_lqa(puVar5);
    nwk_neighbor_get_link_status(puVar5);
    log_write(3,"nwk_neighbor.c",
              "  - Addr[%d:0x%04x:0x%016llx] type(%d) rel(%d) depth(%d) lqa(%d) cost(0x%02x) age(%d)"
              ,uVar1,uVar2,uVar3,uVar4);
  }
  return;
}

