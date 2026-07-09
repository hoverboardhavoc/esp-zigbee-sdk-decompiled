/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> bdb_comm.o -> bdb_comm_network_steering_handle_comm_done
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void bdb_comm_network_steering_handle_comm_done(uint param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_1 == 8) {
_L0:
    if (param_2 == 0) {
      iVar1 = aps_secur_is_centralized();
      if ((iVar1 == 0) || (iVar1 = core_globals_get(), (*(byte *)(iVar1 + 0xd5e) & 4) == 0)) {
        iVar1 = core_globals_get();
        *(undefined1 *)(iVar1 + 0xd4c) = 0;
      }
      else {
        bdb_comm_network_steering_perform_tclk_update();
      }
    }
    else {
_L0:
      iVar1 = core_globals_get();
      *(undefined1 *)(iVar1 + 0xd4c) = 3;
      iVar1 = core_globals_get();
      if ((*(ushort *)(iVar1 + 0xd5e) & 1) != 0) {
        iVar1 = core_globals_get();
        *(byte *)(iVar1 + 0xd5e) = *(byte *)(iVar1 + 0xd5e) & 0xfe;
        bdb_comm_network_steering_perform_join();
      }
    }
_L0:
    iVar1 = core_globals_get();
    if (*(char *)(iVar1 + 0xd4c) != '\0') {
      if (*(char *)(iVar1 + 0xd4c) == '\x01') {
        return;
      }
      bdb_comm_finish_network_steering_with_leave();
      return;
    }
  }
  else {
    if (param_1 < 9) {
      if ((param_1 == 2) || ((1 < param_1 && ((param_1 - 5 & 0xff) < 3)))) {
        if (param_2 == 0) {
          param_2 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/commissioning/bdb/bdb_comm.c"
                                  ,0x157,"bdb_comm_network_steering_handle_comm_done","error != 0");
          goto _L0;
        }
        goto _L0;
      }
    }
    else if (param_1 == 9) {
      if (param_2 == 0) {
        iVar1 = core_globals_get();
        *(undefined1 *)(iVar1 + 0xd4c) = 0;
      }
      else {
        iVar1 = core_globals_get();
        *(undefined1 *)(iVar1 + 0xd4c) = 10;
      }
      goto _L0;
    }
    iVar1 = core_globals_get();
    uVar2 = bdb_comm_step_to_str(*(undefined1 *)(iVar1 + 0xd4e));
    log_write(1,"bdb_comm.c","%s: invalid op(%d)",uVar2,param_1);
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/commissioning/bdb/bdb_comm.c",0x172,
                  "bdb_comm_network_steering_handle_comm_done",&_LC6);
  }
  zdo_dev_set_joined(1);
  bdb_comm_network_steering_on_network();
  return;
}

