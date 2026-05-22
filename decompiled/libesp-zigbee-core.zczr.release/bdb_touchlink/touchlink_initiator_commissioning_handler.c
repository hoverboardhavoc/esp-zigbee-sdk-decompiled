/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.release -> bdb_touchlink.o -> touchlink_initiator_commissioning_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void touchlink_initiator_commissioning_handler(uint8_t task,uint8_t status)

{
  bdb_comm_status_t bVar1;
  undefined3 in_register_00002029;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined3 in_register_0000202d;
  undefined1 uVar5;
  
  iVar3 = CONCAT31(in_register_0000202d,status);
  uVar2 = CONCAT31(in_register_00002029,task);
  if (uVar2 == 2) {
    if (iVar3 == 0) goto _L0;
_L0:
    iVar3 = core_globals_get();
_L0:
    iVar3 = iVar3 + 0x1000;
    uVar5 = 8;
  }
  else {
    if (2 < uVar2) {
      if (uVar2 != 3) {
        if ((uVar2 - 4 & 0xff) < 3) {
          if (iVar3 != 0) {
            iVar4 = core_globals_get();
            *(char *)(iVar4 + 0xd4c) = (uVar2 - 4 != 0) + '\x03';
          }
          else {
            iVar4 = core_globals_get();
            *(undefined1 *)(iVar4 + 0xd4c) = 0;
          }
          zdo_dev_set_joined(iVar3 == 0);
        }
        goto _L0;
      }
      if (iVar3 != 0) {
        iVar3 = core_globals_get();
        *(undefined1 *)(iVar3 + 0xd4c) = 2;
        goto _L0;
      }
_L0:
      iVar3 = core_globals_get();
      bVar1 = touchlink_initiator_associate_target();
      *(bdb_comm_status_t *)(iVar3 + 0xd4c) = bVar1;
      goto _L0;
    }
    if (uVar2 == 0) {
      if (iVar3 != 0) {
        iVar3 = __assert_func(0,0,0);
        goto _L0;
      }
      iVar3 = touchlink_commissioning_scan();
      if (iVar3 == 0) goto _L0;
      if (iVar3 != 5) {
        iVar3 = core_globals_get();
        goto _L0;
      }
      iVar3 = core_globals_get();
      goto _L0;
    }
_L0:
    if (iVar3 != 0) goto _L0;
    iVar3 = touchlink_commissioning_add_sub_device();
    if (iVar3 == 0) {
_L0:
      iVar3 = core_globals_get();
      iVar3 = iVar3 + 0x1000;
      uVar5 = 1;
    }
    else {
      if (iVar3 == 5) goto _L0;
      iVar3 = core_globals_get();
_L0:
      iVar3 = iVar3 + 0x1000;
      uVar5 = 9;
    }
  }
  *(undefined1 *)(iVar3 + -0x2b4) = uVar5;
_L0:
  iVar3 = core_globals_get();
  if (*(char *)(iVar3 + 0xd4c) == '\x01') {
    return;
  }
  touchlink_initiator_stop_commissioning();
  bdb_comm_finish_step();
  iVar3 = core_globals_get();
  bdb_comm_put_app_signal(0x106,*(undefined1 *)(iVar3 + 0xd4c));
  bdb_comm_perform_next_step();
  return;
}

