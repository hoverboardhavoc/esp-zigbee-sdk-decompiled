/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> bdb_comm.o -> bdb_comm_initialization_perform_network_recovery
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void bdb_comm_initialization_perform_network_recovery(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined2 auStack_12 [5];
  
  iVar1 = core_globals_get();
  *(undefined1 *)(iVar1 + 0xd4c) = 3;
  iVar1 = bdb_comm_check_network_parameters();
  if (iVar1 == 0) goto _L0;
  iVar1 = core_globals_get();
  *(undefined1 *)(iVar1 + 0xd4c) = 1;
  iVar1 = nwk_is_device_zc();
  if (iVar1 == 0) {
    iVar1 = nwk_is_device_zr();
    if (iVar1 != 0) {
      iVar1 = core_globals_get();
      if ((*(uint *)(iVar1 + 0xd5c) >> 0x13 & 1) == 0) goto _L0;
    }
    zdo_initiate_rejoin();
    goto _L0;
  }
_L0:
  iVar1 = core_globals_get();
  *(byte *)(iVar1 + 0xb18) = *(byte *)(iVar1 + 0xb18) | 1;
  uVar2 = nwk_get_extended_address();
  uVar3 = nwk_get_short_address();
  iVar1 = nwk_address_update(uVar2,uVar3,auStack_12);
  if (iVar1 == 0) {
    nwk_address_lock_ref(auStack_12[0]);
    iVar1 = aps_secur_is_tc();
    if (iVar1 != 0) goto _L0;
  }
  else {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/commissioning/bdb/bdb_comm.c",0xa1,
                  "bdb_comm_initialization_perform_network_recovery",
                  "(nwk_address_update(nwk_get_extended_address(), nwk_get_short_address(), &ref)) == 0"
                 );
_L0:
    iVar1 = core_globals_get();
    *(ushort *)(iVar1 + 0x9bc) = *(ushort *)(iVar1 + 0x9bc) & 0xffe7 | 8;
    iVar1 = core_globals_get();
    if ((*(byte *)(iVar1 + 0xd5e) & 2) == 0) {
      iVar1 = 1;
    }
    else {
      iVar1 = 2;
    }
    iVar4 = core_globals_get();
    *(ushort *)(iVar4 + 0x9bc) = *(ushort *)(iVar4 + 0x9bc) & 0xfff9 | (ushort)(iVar1 << 1);
  }
  zdo_initiate_commissioning(0x80);
_L0:
  iVar1 = core_globals_get();
  if (*(char *)(iVar1 + 0xd4c) != '\x01') {
    bdb_comm_finish_initialization();
  }
  return;
}

