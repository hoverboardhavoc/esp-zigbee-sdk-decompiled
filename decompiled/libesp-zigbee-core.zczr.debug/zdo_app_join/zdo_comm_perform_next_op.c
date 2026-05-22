/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_app_join.o -> zdo_comm_perform_next_op
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void zdo_comm_perform_next_op(void)

{
  zdo_comm_operation_t op;
  undefined3 extraout_var;
  int iVar2;
  ezb_err_t error;
  uint uVar1;
  
  op = zdo_comm_get_next_op();
  uVar1 = CONCAT31(extraout_var,op);
  if (uVar1 == 0) {
    zdo_comm_signal_comm_done(0);
    return;
  }
  zdo_comm_clr_pending_op(op);
  iVar2 = core_globals_get();
  *(zdo_comm_operation_t *)(iVar2 + 0xcc0) = op;
  if (uVar1 == 6) {
    error = zdo_secur_start_auth(zdo_comm_handle_op_result,0);
  }
  else if (uVar1 < 7) {
    if (uVar1 != 2) {
      if (uVar1 < 3) {
        if (uVar1 == 1) {
          error = zdo_comm_formation();
          goto _L0;
        }
      }
      else if ((uVar1 - 3 & 0xff) < 3) {
        error = zdo_comm_join();
        goto _L0;
      }
_L0:
      error = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/zdo/zdo_app_join.c",0x13f,
                            "zdo_comm_perform_next_op",&_L0);
      goto _L0;
    }
    error = zdo_comm_discovery();
  }
  else if (uVar1 == 8) {
    error = zdo_comm_device_annce();
  }
  else if (uVar1 == 9) {
    error = zdo_secur_request_tclk(zdo_comm_handle_op_result,0);
  }
  else {
    if (uVar1 != 7) goto _L0;
    error = zdo_comm_device_start();
  }
_L0:
  if (error == 0) {
    return;
  }
_L0:
  zdo_comm_signal_comm_done(error);
  return;
}

