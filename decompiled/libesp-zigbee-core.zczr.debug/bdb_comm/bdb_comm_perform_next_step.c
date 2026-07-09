/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> bdb_comm.o -> bdb_comm_perform_next_step
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void bdb_comm_perform_next_step(void)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = bdb_comm_get_next_step();
  if (uVar1 != 6) {
    iVar2 = core_globals_get();
    *(byte *)(iVar2 + 0xd4f) = ~(byte)(1 << (uVar1 & 0x1f)) & *(byte *)(iVar2 + 0xd4f);
    iVar2 = core_globals_get();
    *(char *)(iVar2 + 0xd4e) = (char)uVar1;
    if (uVar1 == 3) {
      bdb_comm_network_formation();
    }
    else if (uVar1 < 4) {
      if (uVar1 == 1) {
        bdb_comm_touchlink_initiator();
      }
      else if (uVar1 == 2) {
        bdb_comm_network_steering();
      }
      else {
        if (uVar1 != 0) goto _L0;
        bdb_comm_initialization();
      }
    }
    else if (uVar1 == 4) {
      bdb_comm_finding_n_binding();
    }
    else {
      if (uVar1 != 5) {
_L0:
        iVar2 = core_globals_get();
        log_write(1,"bdb_comm.c","Invalid step: 0x%02x",*(undefined1 *)(iVar2 + 0xd4e));
        __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/commissioning/bdb/bdb_comm.c",
                      0x26b,"bdb_comm_perform_next_step",&_LC6);
        bdb_comm_finish_step();
        iVar2 = core_globals_get();
        bdb_comm_put_app_signal(0x102,*(undefined1 *)(iVar2 + 0xd4c));
        bdb_comm_perform_next_step();
        return;
      }
      bdb_comm_touchlink_target();
    }
  }
  return;
}

