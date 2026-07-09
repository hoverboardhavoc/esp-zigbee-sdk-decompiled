/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> mac.o -> mac_perform_next_op
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void mac_perform_next_op(int param_1)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = mac_is_enabled();
  if (iVar2 == 0) {
    return;
  }
  if (*(char *)(param_1 + 0x2e) != '\0') {
    return;
  }
  iVar2 = mac_is_op_pending(param_1,6);
  if (iVar2 == 0) {
    iVar2 = mac_is_op_pending(param_1,1);
    if (iVar2 != 0) {
      uVar1 = 1;
      goto _L0;
    }
    iVar2 = mac_is_op_pending(param_1,2);
    if (iVar2 != 0) {
      uVar1 = 2;
      goto _L0;
    }
    iVar2 = mac_is_op_pending(param_1,3);
    if (iVar2 != 0) {
      uVar1 = 3;
      goto _L0;
    }
    iVar2 = mac_is_op_pending(param_1,7);
    if (iVar2 != 0) {
      uVar1 = 7;
      goto _L0;
    }
    iVar2 = mac_is_op_pending(param_1,8);
    if (iVar2 != 0) {
      uVar1 = 8;
      goto _L0;
    }
    iVar2 = mac_is_op_pending(param_1,5);
    if (iVar2 != 0) {
      uVar1 = 5;
      goto _L0;
    }
    iVar2 = mac_is_op_pending(param_1,4);
    if (iVar2 != 0) {
      uVar1 = 4;
      goto _L0;
    }
_L0:
    mac_do_idle(param_1);
  }
  else {
    uVar1 = 6;
_L0:
    mac_clr_pending_op(param_1,uVar1);
    *(char *)(param_1 + 0x2e) = (char)uVar1;
    mac_stop_timer(param_1);
    if (uVar1 == 3) {
      mac_set_state(param_1,2);
    }
    else {
      if (uVar1 < 4) {
        if (uVar1 == 1) {
          mac_set_state(param_1,1);
          mac_do_active_scan(param_1);
          return;
        }
        if (uVar1 == 2) {
          mac_set_state(param_1,1);
          mac_do_ed_scan(param_1);
          return;
        }
        if (uVar1 != 0) goto _L0;
        goto _L0;
      }
      if (uVar1 == 6) {
        mac_pal_receive(*(undefined1 *)(param_1 + 0x42),*(undefined1 *)(param_1 + 0x41));
        mac_start_timer(param_1,(*(ushort *)(param_1 + 0x1c) + 0x3bf) / 0x3c0 + 1);
        return;
      }
      if (6 < uVar1) goto _L0;
      for (uVar1 = uVar1 - 4; 1 < uVar1; uVar1 = uVar1 - 7) {
_L0:
        __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/mac/mac.c",0x3c6,
                      "mac_perform_next_op",&_LC7);
_L0:
      }
    }
    mac_do_transmit(param_1);
  }
  return;
}

