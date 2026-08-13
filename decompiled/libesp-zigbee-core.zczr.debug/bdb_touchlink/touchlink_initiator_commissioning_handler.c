/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.debug -> bdb_touchlink.o -> touchlink_initiator_commissioning_handler
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
    if (param_2 == 0) {
      iVar2 = core_globals_get();
      uVar1 = touchlink_initiator_associate_target();
      *(undefined1 *)(iVar2 + 0xd4c) = uVar1;
    }
    else {
      iVar2 = core_globals_get();
      *(undefined1 *)(iVar2 + 0xd4c) = 8;
    }
  }
  else if (param_1 < 3) {
    if (param_1 == 0) {
      if (param_2 == 0) {
        iVar2 = touchlink_commissioning_scan();
        if (iVar2 == 0) {
          iVar2 = core_globals_get();
          *(undefined1 *)(iVar2 + 0xd4c) = 1;
        }
        else if (iVar2 == 5) {
          iVar2 = core_globals_get();
          *(undefined1 *)(iVar2 + 0xd4c) = 8;
        }
        else {
          iVar2 = core_globals_get();
          *(undefined1 *)(iVar2 + 0xd4c) = 9;
        }
        goto _L0;
      }
      __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/commissioning/bdb/bdb_touchlink.c",
                    0x1cd,"touchlink_initiator_commissioning_handler",&_LC3);
    }
    else {
      if (param_1 != 1) goto _L0;
      if (param_2 != 0) {
        iVar2 = core_globals_get();
        *(undefined1 *)(iVar2 + 0xd4c) = 8;
        goto _L0;
      }
      iVar2 = touchlink_commissioning_add_sub_device();
      if (iVar2 != 0) {
        if (iVar2 == 5) {
          iVar2 = core_globals_get();
          uVar1 = touchlink_initiator_associate_target();
          *(undefined1 *)(iVar2 + 0xd4c) = uVar1;
        }
        else {
          iVar2 = core_globals_get();
          *(undefined1 *)(iVar2 + 0xd4c) = 9;
        }
        goto _L0;
      }
    }
    iVar2 = core_globals_get();
    *(undefined1 *)(iVar2 + 0xd4c) = 1;
  }
  else if (param_1 == 3) {
    if (param_2 == 0) {
      iVar2 = core_globals_get();
      uVar1 = touchlink_initiator_associate_target();
      *(undefined1 *)(iVar2 + 0xd4c) = uVar1;
    }
    else {
      iVar2 = core_globals_get();
      *(undefined1 *)(iVar2 + 0xd4c) = 2;
    }
  }
  else if ((2 < param_1) && ((param_1 - 4 & 0xff) < 3)) {
    if (param_2 == 0) {
      iVar2 = core_globals_get();
      *(undefined1 *)(iVar2 + 0xd4c) = 0;
      zdo_dev_set_joined(1);
    }
    else {
      if (param_1 == 4) {
        uVar1 = 3;
      }
      else {
        uVar1 = 4;
      }
      iVar2 = core_globals_get();
      *(undefined1 *)(iVar2 + 0xd4c) = uVar1;
      zdo_dev_set_joined(0);
    }
  }
_L0:
  iVar2 = core_globals_get();
  if (*(char *)(iVar2 + 0xd4c) != '\x01') {
    touchlink_initiator_stop_commissioning();
    bdb_comm_finish_touchlink_initiator();
  }
  return;
}

