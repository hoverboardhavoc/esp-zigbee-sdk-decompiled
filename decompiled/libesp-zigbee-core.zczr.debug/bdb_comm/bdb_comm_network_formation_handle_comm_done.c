/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> bdb_comm.o -> bdb_comm_network_formation_handle_comm_done
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void bdb_comm_network_formation_handle_comm_done(zdo_comm_operation_t op,ezb_err_t error)

{
  undefined3 in_register_00002029;
  int iVar1;
  char *pcVar2;
  int iVar3;
  
  iVar1 = CONCAT31(in_register_00002029,op);
  if (iVar1 == 1) {
    if (error == 0) {
      __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/commissioning/bdb/bdb_comm.c",0x1b9,
                    "bdb_comm_network_formation_handle_comm_done","error != 0");
      iVar1 = 1;
    }
    else {
_L0:
      iVar3 = core_globals_get();
      iVar1 = 0x1000;
      *(undefined1 *)(iVar3 + 0xd4c) = 5;
      iVar3 = core_globals_get();
      if ((*(ushort *)(iVar3 + 0xd5e) & 1) == 0) goto _L0;
    }
    iVar3 = core_globals_get();
    *(byte *)(iVar3 + iVar1 + -0x2a2) = *(byte *)(iVar3 + iVar1 + -0x2a2) & 0xfe;
    bdb_comm_network_formation_perform_form();
_L0:
    iVar1 = core_globals_get();
    if (*(char *)(iVar1 + 0xd4c) != '\0') {
      if (*(char *)(iVar1 + 0xd4c) == '\x01') {
        return;
      }
      goto _L0;
    }
  }
  else {
    if (iVar1 == 7) {
      if (error != 0) goto _L0;
      iVar1 = core_globals_get();
      *(undefined1 *)(iVar1 + 0xd4c) = 0;
      goto _L0;
    }
    iVar3 = core_globals_get();
    pcVar2 = bdb_comm_step_to_str(*(bdb_comm_step_t *)(iVar3 + 0xd4e));
    log_write(1,"bdb_comm.c","%s: invalid op(%d)",pcVar2,iVar1);
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/commissioning/bdb/bdb_comm.c",0x1c9,
                  "bdb_comm_network_formation_handle_comm_done",&_LC6);
  }
  zdo_dev_set_joined(1);
  iVar1 = aps_secur_is_tc();
  if (iVar1 != 0) {
    iVar1 = core_globals_get();
    *(ushort *)(iVar1 + 0x9bc) = *(ushort *)(iVar1 + 0x9bc) & 0xffe7 | 8;
    iVar1 = core_globals_get();
    if ((*(byte *)(iVar1 + 0xd5e) & 2) == 0) {
      iVar1 = 1;
    }
    else {
      iVar1 = 2;
    }
    iVar3 = core_globals_get();
    *(ushort *)(iVar3 + 0x9bc) = *(ushort *)(iVar3 + 0x9bc) & 0xfff9 | (ushort)(iVar1 << 1);
  }
_L0:
  bdb_comm_finish_network_formation();
  return;
}

