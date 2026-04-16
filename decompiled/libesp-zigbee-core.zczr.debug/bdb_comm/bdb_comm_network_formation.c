/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> bdb_comm.o -> bdb_comm_network_formation
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void bdb_comm_network_formation(void)

{
  char cVar1;
  _Bool _Var2;
  undefined3 extraout_var;
  int iVar3;
  
  _Var2 = bdb_comm_is_on_network();
  if (CONCAT31(extraout_var,_Var2) == 0) {
    iVar3 = nwk_is_device_zczr();
    if (iVar3 == 0) {
      cVar1 = '\t';
    }
    else {
      iVar3 = core_globals_get();
      *(byte *)(iVar3 + 0xdb2) = *(byte *)(iVar3 + 0xdb2) | 1;
      cVar1 = '\x01';
    }
  }
  else {
    cVar1 = '\f';
  }
  iVar3 = core_globals_get();
  *(char *)(iVar3 + 0xda0) = cVar1;
  if (cVar1 == '\x01') {
    bdb_comm_network_formation_perform_form();
  }
  else {
    bdb_comm_finish_network_formation();
  }
  return;
}

