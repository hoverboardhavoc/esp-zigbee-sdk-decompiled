/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> bdb_comm.o -> bdb_comm_network_formation
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void bdb_comm_network_formation(void)

{
  char cVar1;
  int iVar2;
  
  iVar2 = bdb_comm_is_on_network();
  if (iVar2 == 0) {
    iVar2 = nwk_is_device_zczr();
    if (iVar2 == 0) {
      cVar1 = '\t';
    }
    else {
      iVar2 = core_globals_get();
      *(byte *)(iVar2 + 0xd5e) = *(byte *)(iVar2 + 0xd5e) | 1;
      cVar1 = '\x01';
    }
  }
  else {
    cVar1 = '\f';
  }
  iVar2 = core_globals_get();
  *(char *)(iVar2 + 0xd4c) = cVar1;
  if (cVar1 == '\x01') {
    bdb_comm_network_formation_perform_form();
  }
  else {
    bdb_comm_finish_network_formation();
  }
  return;
}

