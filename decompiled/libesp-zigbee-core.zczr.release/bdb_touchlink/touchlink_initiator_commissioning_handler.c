/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> bdb_touchlink.o -> touchlink_initiator_commissioning_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void touchlink_initiator_commissioning_handler(uint param_1,int param_2)

{
  undefined1 uVar1;
  int iVar2;
  
  if (param_1 == 2) {
    if (param_2 == 0) goto _L0;
_L0:
    iVar2 = core_globals_get();
_L0:
    iVar2 = iVar2 + 0x1000;
    uVar1 = 8;
  }
  else {
    if (2 < param_1) {
      if (param_1 != 3) {
        if ((param_1 - 4 & 0xff) < 3) {
          if (param_2 != 0) {
            iVar2 = core_globals_get();
            *(char *)(iVar2 + 0xd4c) = (param_1 - 4 != 0) + '\x03';
          }
          else {
            iVar2 = core_globals_get();
            *(undefined1 *)(iVar2 + 0xd4c) = 0;
          }
          zdo_dev_set_joined(param_2 == 0);
        }
        goto _L0;
      }
      if (param_2 != 0) {
        iVar2 = core_globals_get();
        *(undefined1 *)(iVar2 + 0xd4c) = 2;
        goto _L0;
      }
_L0:
      iVar2 = core_globals_get();
      uVar1 = touchlink_initiator_associate_target();
      *(undefined1 *)(iVar2 + 0xd4c) = uVar1;
      goto _L0;
    }
    if (param_1 == 0) {
      if (param_2 != 0) {
        param_2 = __assert_func(0,0,0);
        goto _L0;
      }
      iVar2 = touchlink_commissioning_scan();
      if (iVar2 == 0) goto _L0;
      if (iVar2 != 5) {
        iVar2 = core_globals_get();
        goto _L0;
      }
      iVar2 = core_globals_get();
      goto _L0;
    }
_L0:
    if (param_2 != 0) goto _L0;
    iVar2 = touchlink_commissioning_add_sub_device();
    if (iVar2 == 0) {
_L0:
      iVar2 = core_globals_get();
      iVar2 = iVar2 + 0x1000;
      uVar1 = 1;
    }
    else {
      if (iVar2 == 5) goto _L0;
      iVar2 = core_globals_get();
_L0:
      iVar2 = iVar2 + 0x1000;
      uVar1 = 9;
    }
  }
  *(undefined1 *)(iVar2 + -0x2b4) = uVar1;
_L0:
  iVar2 = core_globals_get();
  if (*(char *)(iVar2 + 0xd4c) == '\x01') {
    return;
  }
  touchlink_initiator_stop_commissioning();
  bdb_comm_finish_step();
  iVar2 = core_globals_get();
  bdb_comm_put_app_signal(0x106,*(undefined1 *)(iVar2 + 0xd4c));
  bdb_comm_perform_next_step();
  return;
}

