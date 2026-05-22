/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> bdb_comm.o -> bdb_comm_perform_next_step
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void bdb_comm_perform_next_step(void)

{
  byte bVar1;
  undefined3 extraout_var;
  int iVar3;
  uint uVar2;
  
  bVar1 = bdb_comm_get_next_step();
  uVar2 = CONCAT31(extraout_var,bVar1);
  if (uVar2 != 6) {
    iVar3 = core_globals_get();
    *(byte *)(iVar3 + 0xd4f) = ~(byte)(1 << (bVar1 & 0x1f)) & *(byte *)(iVar3 + 0xd4f);
    iVar3 = core_globals_get();
    *(byte *)(iVar3 + 0xd4e) = bVar1;
    if (uVar2 == 3) {
      bdb_comm_network_formation();
    }
    else if (uVar2 < 4) {
      if (uVar2 == 1) {
        bdb_comm_touchlink_initiator();
      }
      else if (uVar2 == 2) {
        bdb_comm_network_steering();
      }
      else {
        if (uVar2 != 0) goto _L0;
        bdb_comm_initialization();
      }
    }
    else if (uVar2 == 4) {
      bdb_comm_finding_n_binding();
    }
    else {
      if (uVar2 != 5) {
_L0:
        iVar3 = core_globals_get();
        log_write(1,"bdb_comm.c","Invalid step: 0x%02x",*(undefined1 *)(iVar3 + 0xd4e));
        __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/commissioning/bdb/bdb_comm.c",
                      0x26c,"bdb_comm_perform_next_step",&_LC6);
        bdb_comm_finish_step();
        iVar3 = core_globals_get();
        bdb_comm_put_app_signal(0x102,*(bdb_comm_status_t *)(iVar3 + 0xd4c));
        bdb_comm_perform_next_step();
        return;
      }
      bdb_comm_touchlink_target();
    }
  }
  return;
}

