/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> bdb_touchlink.o -> touchlink_initiator_commissioning_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void touchlink_initiator_commissioning_handler(uint8_t task,uint8_t status)

{
  undefined1 uVar1;
  bdb_comm_status_t bVar2;
  undefined3 in_register_00002029;
  uint uVar3;
  int iVar4;
  undefined3 in_register_0000202d;
  
  iVar4 = CONCAT31(in_register_0000202d,status);
  uVar3 = CONCAT31(in_register_00002029,task);
  if (uVar3 == 2) {
    if (iVar4 == 0) {
      iVar4 = core_globals_get();
      bVar2 = touchlink_initiator_associate_target();
      *(bdb_comm_status_t *)(iVar4 + 0xda0) = bVar2;
    }
    else {
      iVar4 = core_globals_get();
      *(undefined1 *)(iVar4 + 0xda0) = 8;
    }
  }
  else if (uVar3 < 3) {
    if (uVar3 == 0) {
      if (iVar4 == 0) {
        iVar4 = touchlink_commissioning_scan();
        if (iVar4 == 0) {
          iVar4 = core_globals_get();
          *(undefined1 *)(iVar4 + 0xda0) = 1;
        }
        else if (iVar4 == 5) {
          iVar4 = core_globals_get();
          *(undefined1 *)(iVar4 + 0xda0) = 8;
        }
        else {
          iVar4 = core_globals_get();
          *(undefined1 *)(iVar4 + 0xda0) = 9;
        }
        goto _L0;
      }
      __assert_func("//build/esp-zigbee/src/core/commissioning/bdb/bdb_touchlink.c",0x1c1,
                    "touchlink_initiator_commissioning_handler",&_LC3);
    }
    else {
      if (uVar3 != 1) goto _L0;
      if (iVar4 != 0) {
        iVar4 = core_globals_get();
        *(undefined1 *)(iVar4 + 0xda0) = 8;
        goto _L0;
      }
      iVar4 = touchlink_commissioning_add_sub_device();
      if (iVar4 != 0) {
        if (iVar4 == 5) {
          iVar4 = core_globals_get();
          bVar2 = touchlink_initiator_associate_target();
          *(bdb_comm_status_t *)(iVar4 + 0xda0) = bVar2;
        }
        else {
          iVar4 = core_globals_get();
          *(undefined1 *)(iVar4 + 0xda0) = 9;
        }
        goto _L0;
      }
    }
    iVar4 = core_globals_get();
    *(undefined1 *)(iVar4 + 0xda0) = 1;
  }
  else if (uVar3 == 3) {
    if (iVar4 == 0) {
      iVar4 = core_globals_get();
      bVar2 = touchlink_initiator_associate_target();
      *(bdb_comm_status_t *)(iVar4 + 0xda0) = bVar2;
    }
    else {
      iVar4 = core_globals_get();
      *(undefined1 *)(iVar4 + 0xda0) = 2;
    }
  }
  else if ((2 < uVar3) && ((uVar3 - 4 & 0xff) < 3)) {
    if (iVar4 == 0) {
      iVar4 = core_globals_get();
      *(undefined1 *)(iVar4 + 0xda0) = 0;
      zdo_dev_set_joined(1);
    }
    else {
      if (uVar3 == 4) {
        uVar1 = 3;
      }
      else {
        uVar1 = 4;
      }
      iVar4 = core_globals_get();
      *(undefined1 *)(iVar4 + 0xda0) = uVar1;
      zdo_dev_set_joined(0);
    }
  }
_L0:
  iVar4 = core_globals_get();
  if (*(char *)(iVar4 + 0xda0) != '\x01') {
    touchlink_initiator_stop_commissioning();
    bdb_comm_finish_touchlink_initiator();
  }
  return;
}

