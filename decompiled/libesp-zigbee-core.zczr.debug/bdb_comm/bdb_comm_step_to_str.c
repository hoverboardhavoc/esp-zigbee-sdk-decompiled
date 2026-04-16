/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> bdb_comm.o -> bdb_comm_step_to_str
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

char * bdb_comm_step_to_str(bdb_comm_step_t step)

{
  undefined3 in_register_00002029;
  uint uVar1;
  int iVar2;
  int *piVar3;
  char *pcVar4;
  
  if (CONCAT31(in_register_00002029,step) < 6) {
    return bdb_comm_step_to_str::step_string[CONCAT31(in_register_00002029,step)];
  }
  __assert_func("//build/esp-zigbee/src/core/commissioning/bdb/bdb_comm.c",0x206,
                "bdb_comm_step_to_str","step < BDB_COMM_STEP_MAX_NR");
  uVar1 = nwk_get_pan_channel();
  if ((0x7ffffff < uVar1) || (uVar1 = nwk_get_pan_channel(), (uVar1 & 0x7ffffff) < 0x800)) {
    return (char *)0x0;
  }
  iVar2 = nwk_get_panid();
  if (iVar2 != 0xffff) {
    piVar3 = (int *)nwk_get_extended_panid();
    if ((*piVar3 != 0 || piVar3[1] != 0) && ((*piVar3 != -1 || (piVar3[1] != -1)))) {
      piVar3 = (int *)nwk_get_extended_address();
      if (*piVar3 == 0 && piVar3[1] == 0) {
        return (char *)0x0;
      }
      if ((*piVar3 == -1) && (piVar3[1] == -1)) {
        return (char *)0x0;
      }
      iVar2 = nwk_get_short_address();
      if (iVar2 == 0) {
        iVar2 = nwk_is_device_zc();
        if (iVar2 == 0) {
          return (char *)0x0;
        }
      }
      else {
        uVar1 = nwk_get_short_address();
        if (0xfff7 < uVar1) {
          return (char *)0x0;
        }
      }
      pcVar4 = (char *)nwk_is_authed();
      if (pcVar4 == (char *)0x0) {
        return (char *)0x0;
      }
      nwk_get_panid();
      nwk_set_panid();
      nwk_get_short_address();
      nwk_set_short_address();
      nwk_get_extended_address();
      nwk_set_extended_address();
      nwk_get_pan_channel();
      nwk_set_pan_channel();
      nwk_get_rx_on_when_idle();
      nwk_set_rx_on_when_idle();
      return pcVar4;
    }
  }
  return (char *)0x0;
}

