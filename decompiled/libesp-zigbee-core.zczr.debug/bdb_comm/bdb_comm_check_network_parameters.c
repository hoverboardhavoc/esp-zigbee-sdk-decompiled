/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> bdb_comm.o -> bdb_comm_check_network_parameters
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

_Bool bdb_comm_check_network_parameters(void)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  
  uVar2 = nwk_get_pan_channel();
  if (uVar2 < 0x8000000) {
    uVar2 = nwk_get_pan_channel();
    if (0x7ff < (uVar2 & 0x7ffffff)) {
      iVar1 = nwk_get_panid();
      if (iVar1 != 0xffff) {
        piVar3 = (int *)nwk_get_extended_panid();
        if ((*piVar3 != 0 || piVar3[1] != 0) && ((*piVar3 != -1 || (piVar3[1] != -1)))) {
          piVar3 = (int *)nwk_get_extended_address();
          if (*piVar3 == 0 && piVar3[1] == 0) {
            iVar1 = 0;
          }
          else if ((*piVar3 == -1) && (piVar3[1] == -1)) {
            iVar1 = 0;
          }
          else {
            iVar1 = nwk_get_short_address();
            if (iVar1 == 0) {
              iVar1 = nwk_is_device_zc();
              if (iVar1 == 0) goto _L0;
            }
            else {
              uVar2 = nwk_get_short_address();
              if (0xfff7 < uVar2) {
                iVar1 = 0;
                goto _L0;
              }
            }
            iVar1 = nwk_is_authed();
            if (iVar1 != 0) {
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
            }
          }
          goto _L0;
        }
      }
      iVar1 = 0;
      goto _L0;
    }
  }
  iVar1 = 0;
_L0:
  return SUB41(iVar1,0);
}

