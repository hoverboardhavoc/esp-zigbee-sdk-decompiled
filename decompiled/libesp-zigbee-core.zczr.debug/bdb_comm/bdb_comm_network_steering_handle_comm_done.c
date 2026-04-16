/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> bdb_comm.o -> bdb_comm_network_steering_handle_comm_done
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void bdb_comm_network_steering_handle_comm_done(zdo_comm_operation_t op,ezb_err_t error)

{
  undefined3 in_register_00002029;
  uint uVar1;
  int iVar2;
  char *pcVar3;
  
  uVar1 = CONCAT31(in_register_00002029,op);
  if (uVar1 == 8) {
_L0:
    if (error == 0) {
      iVar2 = aps_secur_is_centralized();
      if ((iVar2 == 0) || (iVar2 = core_globals_get(), (*(byte *)(iVar2 + 0xdb2) & 4) == 0)) {
        iVar2 = core_globals_get();
        *(undefined1 *)(iVar2 + 0xda0) = 0;
      }
      else {
        bdb_comm_network_steering_perform_tclk_update();
      }
    }
    else {
_L0:
      iVar2 = core_globals_get();
      *(undefined1 *)(iVar2 + 0xda0) = 3;
      iVar2 = core_globals_get();
      if ((*(ushort *)(iVar2 + 0xdb2) & 1) != 0) {
        iVar2 = core_globals_get();
        *(byte *)(iVar2 + 0xdb2) = *(byte *)(iVar2 + 0xdb2) & 0xfe;
        bdb_comm_network_steering_perform_join();
      }
    }
_L0:
    iVar2 = core_globals_get();
    if (*(char *)(iVar2 + 0xda0) != '\0') {
      if (*(char *)(iVar2 + 0xda0) == '\x01') {
        return;
      }
      if (5 < uVar1) {
        bdb_comm_finish_network_steering_with_leave();
        return;
      }
      bdb_comm_finish_network_steering();
      return;
    }
  }
  else {
    if (uVar1 < 9) {
      if ((uVar1 == 2) || ((1 < uVar1 && ((uVar1 - 5 & 0xff) < 3)))) {
        if (error == 0) {
          error = __assert_func("//build/esp-zigbee/src/core/commissioning/bdb/bdb_comm.c",0x14c,
                                "bdb_comm_network_steering_handle_comm_done","error != 0");
          goto _L0;
        }
        goto _L0;
      }
    }
    else if (uVar1 == 9) {
      if (error == 0) {
        iVar2 = core_globals_get();
        *(undefined1 *)(iVar2 + 0xda0) = 0;
      }
      else {
        iVar2 = core_globals_get();
        *(undefined1 *)(iVar2 + 0xda0) = 10;
      }
      goto _L0;
    }
    iVar2 = core_globals_get();
    pcVar3 = bdb_comm_step_to_str(*(bdb_comm_step_t *)(iVar2 + 0xda2));
    log_write(1,"bdb_comm.c","%s: invalid op(%d)",pcVar3,uVar1);
    __assert_func("//build/esp-zigbee/src/core/commissioning/bdb/bdb_comm.c",0x167,
                  "bdb_comm_network_steering_handle_comm_done",&_LC6);
  }
  zdo_dev_set_joined(1);
  bdb_comm_network_steering_on_network();
  return;
}

