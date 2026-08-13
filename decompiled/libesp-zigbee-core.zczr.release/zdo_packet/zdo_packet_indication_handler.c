/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
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
  undefined1 uStack_29;
  undefined1 auStack_28 [20];
  undefined4 in_stack_ffffffec;
  
  if (param_1 == (char *)0x0) {
    return 0x80;
  }
  if (*(short *)(param_1 + 6) < 0) {
    iVar5 = 0x80;
    if (param_1 != (char *)0x0) {
      cVar1 = *param_1;
      iVar5 = core_globals_get();
      piVar3 = *(int **)(iVar5 + 0xcac);
      iVar5 = 0xfe;
      if (piVar3 != (int *)0x0) {
        for (; pcVar4 = (char *)(piVar3 + -9), pcVar4 != (char *)0xffffffdc; piVar3 = (int *)*piVar3
            ) {
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
  if (param_1 == (char *)0x0) {
    return 0x80;
  }
  uVar2 = *(ushort *)(param_1 + 6);
  if (uVar2 < 0x20) {
    iVar5 = zdo_device_service_discovery_req_handler();
  }
  else if (uVar2 < 0x30) {
    iVar5 = zdo_bind_mgmt_req_handler();
  }
  else {
    if (0x3f < uVar2) goto _L0;
    iVar5 = zdo_nwk_mgmt_req_handler();
  }
  if (iVar5 != 0x84) {
    return iVar5;
  }
_L0:
  memset(auStack_28,0,0x18);
  iVar5 = 0xfe;
  if ((*(ushort *)(param_1 + 2) < 0xfff8) &&
     (iVar5 = zdo_packet_response_init(auStack_28,param_1,*(ushort *)(param_1 + 6) | 0x8000),
     iVar5 == 0)) {
    uStack_29 = 0x84;
    zmsg_append_bytes(in_stack_ffffffec,1,&uStack_29);
    iVar5 = ezb_err_to_zdp_status();
    if (iVar5 == 0) {
      iVar5 = zdo_packet_send();
    }
    else {
      zdo_packet_free(auStack_28);
    }
  }
  return iVar5;
}

