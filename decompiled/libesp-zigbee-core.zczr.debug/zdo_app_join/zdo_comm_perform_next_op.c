/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_app_join.o -> zdo_comm_perform_next_op
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zdo_comm_perform_next_op(void)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = zdo_comm_get_next_op();
  if (uVar1 == 0) {
    zdo_comm_signal_comm_done(0);
    return;
  }
  zdo_comm_clr_pending_op();
  iVar2 = core_globals_get();
  *(char *)(iVar2 + 0xcc0) = (char)uVar1;
  if (uVar1 == 6) {
    iVar2 = zdo_secur_start_auth(zdo_comm_handle_op_result,0);
  }
  else if (uVar1 < 7) {
    if (uVar1 != 2) {
      if (uVar1 < 3) {
        if (uVar1 == 1) {
          iVar2 = zdo_comm_formation();
          goto _L0;
        }
      }
      else if ((uVar1 - 3 & 0xff) < 3) {
        iVar2 = zdo_comm_join();
        goto _L0;
      }
_L0:
      __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/zdo/zdo_app_join.c",0x138,
                    "zdo_comm_perform_next_op",&_L0);
      goto _L0;
    }
    iVar2 = zdo_comm_discovery();
  }
  else if (uVar1 == 8) {
    iVar2 = zdo_comm_device_annce();
  }
  else if (uVar1 == 9) {
    iVar2 = zdo_secur_request_tclk(zdo_comm_handle_op_result,0);
  }
  else {
    if (uVar1 != 7) goto _L0;
    iVar2 = zdo_comm_device_start();
  }
_L0:
  if (iVar2 == 0) {
    return;
  }
_L0:
  zdo_comm_signal_comm_done();
  return;
}

