/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> zdo_packet.o -> zdo_packet_indication_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int zdo_packet_indication_handler(char *param_1)

{
  char cVar1;
  ushort uVar2;
  int *piVar3;
  char *pcVar4;
  int iVar5;
  
  if (param_1 == (char *)0x0) {
    return 0x80;
  }
  if (-1 < *(short *)(param_1 + 6)) {
    if (param_1 == (char *)0x0) {
      iVar5 = 0x80;
    }
    else {
      uVar2 = *(ushort *)(param_1 + 6);
      if (uVar2 < 0x20) {
        iVar5 = zdo_device_service_discovery_req_handler();
        return iVar5;
      }
      if (uVar2 < 0x30) {
        iVar5 = zdo_bind_mgmt_req_handler();
        return iVar5;
      }
      iVar5 = 0x84;
      if (uVar2 < 0x40) {
        iVar5 = zdo_nwk_mgmt_req_handler();
        return iVar5;
      }
    }
    return iVar5;
  }
  iVar5 = 0x80;
  if (param_1 != (char *)0x0) {
    cVar1 = *param_1;
    iVar5 = core_globals_get();
    piVar3 = *(int **)(iVar5 + 0xcac);
    iVar5 = 0xfe;
    if (piVar3 != (int *)0x0) {
      for (; pcVar4 = (char *)(piVar3 + -9), pcVar4 != (char *)0xffffffdc; piVar3 = (int *)*piVar3)
      {
        if (*pcVar4 == cVar1) {
          memcpy(param_1 + 8,piVar3 + -3,0xc);
          uVar2 = *(ushort *)(param_1 + 6);
          if (uVar2 < 0x8020) {
            iVar5 = zdo_device_service_discovery_rsp_handler(param_1);
          }
          else if (uVar2 < 0x8030) {
            iVar5 = zdo_bind_mgmt_rsp_handler(param_1);
          }
          else {
            if (0x803f < uVar2) {
              return 0x84;
            }
            iVar5 = zdo_nwk_mgmt_rsp_handler(param_1);
          }
          if (iVar5 != 0) {
            return iVar5;
          }
          *(byte *)(piVar3 + -4) = *(byte *)(piVar3 + -4) | 1;
          if (*(char *)(piVar3 + -3) != '\x01') {
            return 0;
          }
          zdo_packet_ctx_list_remove_entry(pcVar4);
          zdo_packet_ctx_free_entry(pcVar4);
          return 0;
        }
      }
      iVar5 = 0xfe;
    }
  }
  return iVar5;
}

