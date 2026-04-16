/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> nwk_nlme.o -> nwk_leave_request
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t nwk_leave_request(nwk_leave_req_t *req)

{
  ezb_shortaddr_t dst_addr;
  int iVar1;
  int *piVar2;
  
  if (req == (nwk_leave_req_t *)0x0) {
    return 2;
  }
  iVar1 = core_globals_get();
  if (*(char *)(iVar1 + 0xac0) == '\0') {
    iVar1 = nwk_is_joined();
    if (iVar1 == 0) {
      return 0x2c2;
    }
    if (*(int *)&(req->device_address).field_0 != 0 ||
        *(int *)((int)&(req->device_address).field_0 + 4) != 0) {
      piVar2 = (int *)nwk_get_extended_address();
      if ((*(int *)&(req->device_address).field_0 != *piVar2) ||
         (*(int *)((int)&(req->device_address).field_0 + 4) != piVar2[1])) {
        iVar1 = nwk_is_device_zczr();
        if ((iVar1 != 0) &&
           (((iVar1 = nwk_neighbor_table_get_by_extended(req), iVar1 != 0 &&
             ((*(uint *)(iVar1 + 0xc) & 3) == 2)) && ((*(uint *)(iVar1 + 0xc) & 0x3c0) != 0x140))))
        {
          dst_addr = nwk_neighbor_get_shortaddr();
          nwk_send_leave(dst_addr,(_Bool)(req->field_0x8 & 1),(_Bool)((byte)req->field_0x8 >> 1 & 1)
                        );
          return 0;
        }
        return 0x2c8;
      }
    }
    nwk_do_leave('\0',(_Bool)(req->field_0x8 & 1),(_Bool)((byte)req->field_0x8 >> 1 & 1));
    return 0;
  }
  return 3;
}

