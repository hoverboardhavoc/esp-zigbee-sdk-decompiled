/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> bdb_comm.o -> bdb_comm_check_network_parameters
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int bdb_comm_check_network_parameters(void)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  
  uVar1 = nwk_get_pan_channel();
  if ((0x7ffffff < uVar1) || (uVar1 = nwk_get_pan_channel(), (uVar1 & 0x7ffffff) < 0x800)) {
    return 0;
  }
  iVar2 = nwk_get_panid();
  if (iVar2 != 0xffff) {
    piVar3 = (int *)nwk_get_extended_panid();
    if ((*piVar3 != 0 || piVar3[1] != 0) && ((*piVar3 != -1 || (piVar3[1] != -1)))) {
      piVar3 = (int *)nwk_get_extended_address();
      if (*piVar3 == 0 && piVar3[1] == 0) {
        return 0;
      }
      if ((*piVar3 == -1) && (piVar3[1] == -1)) {
        return 0;
      }
      iVar2 = nwk_get_short_address();
      if (iVar2 == 0) {
        iVar2 = nwk_is_device_zc();
        if (iVar2 == 0) {
          return 0;
        }
      }
      else {
        uVar1 = nwk_get_short_address();
        if (0xfff7 < uVar1) {
          return 0;
        }
      }
      iVar2 = nwk_is_authed();
      if (iVar2 == 0) {
        return 0;
      }
      piVar3 = (int *)aps_secur_get_tc_address();
      if (*piVar3 == 0 && piVar3[1] == 0) {
        return 0;
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
      return iVar2;
    }
  }
  return 0;
}

