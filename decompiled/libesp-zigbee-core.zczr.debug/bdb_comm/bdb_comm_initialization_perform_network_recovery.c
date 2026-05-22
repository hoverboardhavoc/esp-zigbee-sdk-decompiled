/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> bdb_comm.o -> bdb_comm_initialization_perform_network_recovery
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void bdb_comm_initialization_perform_network_recovery(void)

{
  _Bool _Var1;
  int iVar2;
  undefined3 extraout_var;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  undefined2 uStack_16;
  undefined2 uStack_14;
  nwk_addr_ref_t ref;
  
  iVar2 = core_globals_get();
  *(undefined1 *)(iVar2 + 0xd4c) = 3;
  _Var1 = bdb_comm_check_network_parameters();
  if (CONCAT31(extraout_var,_Var1) == 0) goto _L0;
  iVar2 = nwk_is_device_zc();
  if (iVar2 == 0) {
    iVar2 = nwk_is_device_zr();
    if (iVar2 != 0) {
      iVar2 = core_globals_get();
      if ((*(uint *)(iVar2 + 0xd5c) >> 0x13 & 1) == 0) goto _L0;
    }
    iVar2 = core_globals_get();
    *(undefined1 *)(iVar2 + 0xd4c) = 1;
    zdo_initiate_rejoin();
    goto _L0;
  }
_L0:
  iVar2 = core_globals_get();
  *(undefined1 *)(iVar2 + 0xd4c) = 0;
  iVar2 = core_globals_get();
  *(byte *)(iVar2 + 0xb18) = *(byte *)(iVar2 + 0xb18) | 1;
  uVar3 = nwk_get_extended_address();
  uVar4 = nwk_get_short_address();
  iVar2 = nwk_address_update(uVar3,uVar4,&uStack_16);
  if (iVar2 == 0) {
    nwk_address_lock_ref(uStack_16);
    uStack_14 = 0;
    ref._0_1_ = 0;
    iVar2 = nwk_start_router(&uStack_14);
    if (iVar2 != 0) goto _L0;
    zdo_dev_set_joined(1);
    iVar2 = aps_secur_is_tc();
    if (iVar2 == 0) goto _L0;
    iVar2 = core_globals_get();
    *(ushort *)(iVar2 + 0x9bc) = *(ushort *)(iVar2 + 0x9bc) & 0xffe7 | 8;
    iVar2 = core_globals_get();
    if ((*(byte *)(iVar2 + 0xd5e) & 2) == 0) goto _L0;
    iVar2 = 2;
  }
  else {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/commissioning/bdb/bdb_comm.c",0xa1,
                  "bdb_comm_initialization_perform_network_recovery",
                  "(nwk_address_update(nwk_get_extended_address(), nwk_get_short_address(), &ref)) == 0"
                 );
_L0:
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/commissioning/bdb/bdb_comm.c",0xa3,
                  "bdb_comm_initialization_perform_network_recovery",
                  "(nwk_start_router(&(nwk_start_router_req_t){0})) == 0");
_L0:
    iVar2 = 1;
  }
  iVar5 = core_globals_get();
  *(ushort *)(iVar5 + 0x9bc) = *(ushort *)(iVar5 + 0x9bc) & 0xfff9 | (ushort)(iVar2 << 1);
_L0:
  iVar2 = core_globals_get();
  if (*(char *)(iVar2 + 0xd4c) != '\x01') {
    bdb_comm_finish_initialization();
  }
  return;
}

