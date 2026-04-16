/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_ed_mngr.o -> nwk_ed_handle_poll_confirm
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_ed_handle_poll_confirm(uint8_t iface_id,mac_poll_cnf_t *cnf)

{
  mac_status_t mVar1;
  uint uVar2;
  _Bool success;
  undefined3 in_register_00002029;
  int iVar3;
  
  iVar3 = core_globals_get(CONCAT31(in_register_00002029,iface_id));
  if ((*(uint *)(iVar3 + 0xb14) >> 0x15 & 1) != 0) {
    if (cnf->status == '\0') {
      success = true;
    }
    else if (cnf->status == 0xeb) {
      success = true;
    }
    else {
      success = false;
    }
    iVar3 = core_globals_get();
    if (((*(byte *)(iVar3 + 0xaf8) & 0x40) != 0) &&
       (iVar3 = core_globals_get(), (*(byte *)(iVar3 + 0xa28) & 1) != 0)) {
      nwk_ed_process_keepalive_result(success);
    }
    iVar3 = core_globals_get();
    uVar2 = *(uint *)(iVar3 + 0xb14) >> 0x15 & 1;
    if (uVar2 != 0) {
      mVar1 = cnf->status;
      if (mVar1 == 0xe1) {
        iVar3 = core_globals_get();
        *(byte *)(iVar3 + 0xb16) = *(byte *)(iVar3 + 0xb16) | 0x10;
      }
      else if ((mVar1 == 0xeb) || (mVar1 == '\0')) {
        iVar3 = core_globals_get();
        if (*(short *)(iVar3 + 0xb14) == 0) {
          uVar2 = 0;
        }
        else {
          iVar3 = core_globals_get();
          *(short *)(iVar3 + 0xb14) = *(short *)(iVar3 + 0xb14) + -1;
          iVar3 = core_globals_get();
          if (*(short *)(iVar3 + 0xb14) == 0) {
            iVar3 = core_globals_get();
            *(byte *)(iVar3 + 0xb16) = *(byte *)(iVar3 + 0xb16) & 0xf0;
          }
          else {
            uVar2 = 0;
          }
        }
        iVar3 = core_globals_get();
        if ((*(byte *)(iVar3 + 0xb16) & 0x10) == 0) {
          if (uVar2 == 0) {
            return;
          }
        }
        else {
          iVar3 = core_globals_get();
          *(byte *)(iVar3 + 0xb16) = *(byte *)(iVar3 + 0xb16) & 0xef;
        }
      }
      else {
        log_write(2,"nwk_ed_mngr.c","Failed to send data poll: 0x%02x");
        iVar3 = core_globals_get();
        uVar2 = *(uint *)(iVar3 + 0xb14);
        iVar3 = core_globals_get();
        *(byte *)(iVar3 + 0xb16) =
             *(byte *)(iVar3 + 0xb16) & 0xef | (byte)((uVar2 >> 0x14 & 1 ^ 1) << 4);
      }
      nwk_pim_schedule_next_poll(true);
    }
  }
  return;
}

