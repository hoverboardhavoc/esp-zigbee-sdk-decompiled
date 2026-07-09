/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> nwk_neighbor.o -> nwk_neighbor_table_handle_link_status_period
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_neighbor_table_handle_link_status_period(void)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  iVar1 = 0;
  while (iVar1 = nwk_neighbor_table_next(iVar1), iVar1 != 0) {
    uVar3 = *(uint *)(iVar1 + 0xc);
    if ((uVar3 & 3) < 2) {
      if (*(char *)(iVar1 + 0x19) != '\0') {
        *(char *)(iVar1 + 0x19) = *(char *)(iVar1 + 0x19) + -1;
      }
      if (*(char *)(iVar1 + 0x18) != '\0') {
        *(char *)(iVar1 + 0x18) = *(char *)(iVar1 + 0x18) + -1;
      }
      iVar2 = core_globals_get();
      uVar4 = *(uint *)(iVar1 + 0xc);
      if ((uVar3 >> 0x12 & 0xff) < (uint)*(byte *)(iVar2 + 0xa25)) {
        *(uint *)(iVar1 + 0xc) = uVar4 & 0xfc03ffff | ((uVar4 >> 0x12) + 1 & 0xff) << 0x12;
        if (*(short *)(iVar1 + 0x12) != -1) {
          *(short *)(iVar1 + 0x12) = *(short *)(iVar1 + 0x12) + 1;
        }
      }
      else {
        if ((uVar4 >> 0x1a & 7) != 0) {
          *(uint *)(iVar1 + 0xc) = uVar4 & 0xe3ffffff;
          nwk_neighbor_set_outgoing_cost_part_0(iVar1);
          nwk_neighbor_clear_lqa(iVar1);
        }
        if ((*(uint *)(iVar1 + 0xc) & 3) == 0) {
          iVar2 = core_globals_get();
          if ((*(byte *)(iVar2 + 0xa2a) & 8) != 0) {
            iVar2 = core_globals_get();
            *(byte *)(iVar2 + 0xa2a) = *(byte *)(iVar2 + 0xa2a) & 0xf7;
          }
        }
      }
    }
  }
  return;
}

